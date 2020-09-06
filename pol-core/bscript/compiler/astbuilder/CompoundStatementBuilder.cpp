#include "CompoundStatementBuilder.h"

#include "compiler/ast/ArrayInitializer.h"
#include "compiler/ast/Block.h"
#include "compiler/ast/CaseDispatchDefaultSelector.h"
#include "compiler/ast/CaseDispatchGroup.h"
#include "compiler/ast/CaseDispatchGroups.h"
#include "compiler/ast/CaseDispatchSelectors.h"
#include "compiler/ast/CaseStatement.h"
#include "compiler/ast/ConstDeclaration.h"
#include "compiler/ast/ExitStatement.h"
#include "compiler/ast/Expression.h"
#include "compiler/ast/ForeachLoop.h"
#include "compiler/ast/FunctionCall.h"
#include "compiler/ast/Identifier.h"
#include "compiler/ast/IfThenElseStatement.h"
#include "compiler/ast/IntegerValue.h"
#include "compiler/ast/JumpStatement.h"
#include "compiler/ast/ReturnStatement.h"
#include "compiler/ast/StringValue.h"
#include "compiler/ast/WhileLoop.h"
#include "compiler/astbuilder/BuilderWorkspace.h"
#include "compiler/model/CompilerWorkspace.h"

using EscriptGrammar::EscriptParser;

namespace Pol::Bscript::Compiler
{
CompoundStatementBuilder::CompoundStatementBuilder(
    const SourceFileIdentifier& source_file_identifier, BuilderWorkspace& workspace )
  : SimpleStatementBuilder( source_file_identifier, workspace )
{
}

void CompoundStatementBuilder::add_statements(
    EscriptParser::StatementContext* ctx, std::vector<std::unique_ptr<Statement>>& statements )
{
  if ( auto expr_ctx = ctx->expression() )
  {
    statements.push_back( consume_statement_result( expression( expr_ctx ) ) );
  }
  else if ( auto if_st = ctx->ifStatement() )
  {
    statements.push_back( if_statement( if_st ) );
  }
  else if ( auto var_statement = ctx->varStatement() )
  {
    add_var_statements( var_statement, statements );
  }
  else if ( auto return_st = ctx->returnStatement() )
  {
    statements.push_back( return_statement( return_st ) );
  }
  else if ( auto foreach_statement = ctx->foreachStatement() )
  {
    statements.push_back( foreach_loop( foreach_statement ) );
  }
  else if ( auto while_statement = ctx->whileStatement() )
  {
    statements.push_back( while_loop( while_statement ) );
  }
  else if ( auto break_st = ctx->breakStatement() )
  {
    statements.push_back( break_statement( break_st ) );
  }
  else if ( auto continue_st = ctx->continueStatement() )
  {
    statements.push_back( continue_statement( continue_st ) );
  }
  else if ( auto case_st = ctx->caseStatement() )
  {
    statements.push_back( case_statement( case_st ) );
  }
  else if ( auto exit = ctx->exitStatement() )
  {
    statements.push_back( std::make_unique<ExitStatement>( location_for( *exit ) ) );
  }
  else if ( auto const_statement = ctx->constStatement() )
  {
    workspace.compiler_workspace.const_declarations.push_back(
        const_declaration( const_statement ) );
  }
  else
  {
    location_for( *ctx ).internal_error( "unhandled statement" );
  }
}

std::vector<std::unique_ptr<Statement>> CompoundStatementBuilder::block_statements(
        EscriptParser::BlockContext* ctx )
{
  std::vector<std::unique_ptr<Statement>> statements;

  for ( auto statement_context : ctx->statement() )
  {
    add_statements( statement_context, statements );
  }

  return statements;
}

std::unique_ptr<Block> CompoundStatementBuilder::block( EscriptParser::BlockContext* ctx )
{
  auto statements = block_statements( ctx );
  return std::make_unique<Block>( location_for( *ctx ), std::move( statements ) );
}

std::unique_ptr<CaseStatement> CompoundStatementBuilder::case_statement(
    EscriptParser::CaseStatementContext* ctx )
{
  // possibilities:
  // case (expr)
  //  4:
  //  "xz":
  //  CONSTANT:
  //  default:
  auto loc = location_for( *ctx );
  std::string case_label;
  if ( auto statement_label = ctx->statementLabel() )
    case_label = text( statement_label->IDENTIFIER() );

  auto determinant = expression( ctx->expression() );

  std::vector<std::unique_ptr<CaseDispatchGroup>> dispatch_groups;

  for ( auto group : ctx->switchBlockStatementGroup() )
  {
    std::vector<std::unique_ptr<Node>> selectors;

    for ( auto group_label : group->switchLabel() )
    {
      if ( auto integer_literal = group_label->integerLiteral() )
      {
        selectors.push_back( integer_value( integer_literal ) );
      }
      else if ( auto identifier = group_label->IDENTIFIER() )
      {
        selectors.push_back(
            std::make_unique<Identifier>( location_for( *identifier ), text( identifier ) ) );
      }
      else if ( auto string_literal = group_label->STRING_LITERAL() )
      {
        selectors.push_back( string_value( string_literal ) );
      }
      else if ( auto dflt = group_label->DEFAULT() )
      {
        selectors.push_back(
            std::make_unique<CaseDispatchDefaultSelector>( location_for( *dflt ) ) );
      }
    }
    auto dispatch_selectors =
        std::make_unique<CaseDispatchSelectors>( location_for( *group ), std::move( selectors ) );
    auto body = block( group->block() );
    auto dispatch_group = std::make_unique<CaseDispatchGroup>(
        location_for( *group ), std::move( dispatch_selectors ), std::move( body ) );
    dispatch_groups.push_back( std::move( dispatch_group ) );
  }
  auto holder = std::make_unique<CaseDispatchGroups>( loc, std::move( dispatch_groups ) );

  return std::make_unique<CaseStatement>( loc, std::move( case_label ), std::move( determinant ),
                                          std::move( holder ) );
}

std::unique_ptr<Expression> CompoundStatementBuilder::foreach_iterable_expression(
    EscriptParser::ForeachIterableExpressionContext* ctx )
{
  if ( auto identifier = ctx->IDENTIFIER() )
  {
    return std::make_unique<Identifier>( location_for( *identifier ), text( identifier ) );
  }
  else if ( auto m_call = ctx->functionCall() )
  {
    return function_call( m_call, "" );
  }
  else if ( auto scoped_call = ctx->scopedFunctionCall() )
  {
    return scoped_function_call( scoped_call );
  }
  else if ( auto array_init = ctx->explicitArrayInitializer() )
  {
    return array_initializer( array_init );
  }
  else if ( auto bare_array = ctx->bareArrayInitializer() )
  {
    return array_initializer( bare_array );
  }
  else if ( auto par_ex = ctx->parExpression() )
  {
    return expression( par_ex->expression() );
  }
  else
  {
    location_for( *ctx ).internal_error( "unhandled foreach iterable expression" );
  }
}

std::unique_ptr<ForeachLoop> CompoundStatementBuilder::foreach_loop(
    EscriptParser::ForeachStatementContext* ctx )
{
  auto source_location = location_for( *ctx );
  std::string label;
  if ( auto statement_label = ctx->statementLabel() )
    label = text( statement_label->IDENTIFIER() );
  std::string iterator_name = text( ctx->IDENTIFIER() );
  auto iterable = foreach_iterable_expression( ctx->foreachIterableExpression() );
  auto body = block( ctx->block() );
  return std::make_unique<ForeachLoop>( source_location, std::move( label ),
                                        std::move( iterator_name ), std::move( iterable ),
                                        std::move( body ) );
}

std::unique_ptr<Statement> CompoundStatementBuilder::if_statement(
    EscriptParser::IfStatementContext* ctx )
{
  //
  // if (expr0) block0 elseif (expr1) block1 ... elseif (exprN-1) blockN-1 else blockN
  //

  auto blocks = ctx->block();
  auto par_expression = ctx->parExpression();

  auto else_clause =
      ctx->ELSE() ? block( blocks.at( blocks.size() - 1 ) ) : std::unique_ptr<Node>();

  auto if_statement_ast = std::unique_ptr<Statement>();

  size_t num_expressions = par_expression.size();
  for ( auto clause_index = num_expressions; clause_index != 0; )
  {
    --clause_index;
    auto expression_ctx = par_expression.at( clause_index );
    auto expression_ast = expression( expression_ctx->expression() );
    auto consequent_ast = block( blocks.at( clause_index ) );
    auto alternative_ast =
        if_statement_ast ? std::move( if_statement_ast ) : std::move( else_clause );
    auto source_location = location_for( *expression_ctx );

    if ( alternative_ast )
    {
      if_statement_ast = std::make_unique<IfThenElseStatement>(
          source_location, std::move( expression_ast ), std::move( consequent_ast ),
          std::move( alternative_ast ) );
    }
    else
    {
      if_statement_ast = std::make_unique<IfThenElseStatement>(
          source_location, std::move( expression_ast ), std::move( consequent_ast ) );
    }
  }

  return if_statement_ast;
}

std::unique_ptr<WhileLoop> CompoundStatementBuilder::while_loop(
    EscriptParser::WhileStatementContext* ctx )
{
  std::string label;
  if ( auto statement_label = ctx->statementLabel() )
    label = text( statement_label->IDENTIFIER() );
  auto source_location = location_for( *ctx );
  auto predicate = expression( ctx->parExpression()->expression() );
  auto body = block( ctx->block() );
  return std::make_unique<WhileLoop>( source_location, std::move( label ), std::move( predicate ),
                                        std::move( body ) );
}

}  // namespace Pol::Bscript::Compiler
