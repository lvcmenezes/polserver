set (bscript_sources    # sorted !
  ../../lib/EscriptGrammar/EscriptLexer.cpp
  ../../lib/EscriptGrammar/EscriptLexer.h
  ../../lib/EscriptGrammar/EscriptParser.cpp
  ../../lib/EscriptGrammar/EscriptParser.h
  ../../lib/EscriptGrammar/EscriptParserBaseListener.cpp
  ../../lib/EscriptGrammar/EscriptParserBaseListener.h
  ../../lib/EscriptGrammar/EscriptParserListener.cpp
  ../../lib/EscriptGrammar/EscriptParserListener.h
  CMakeSources.cmake
  StdAfx.h
  StoredToken.cpp
  StoredToken.h
  compiler/Compiler.cpp
  compiler/Compiler.h
  compiler/LegacyFunctionOrder.h
  compiler/analyzer/Disambiguator.cpp
  compiler/analyzer/Disambiguator.h
  compiler/analyzer/SemanticAnalyzer.cpp
  compiler/analyzer/SemanticAnalyzer.h
  compiler/ast/Argument.cpp
  compiler/ast/Argument.h
  compiler/ast/BinaryOperator.cpp
  compiler/ast/BinaryOperator.h
  compiler/ast/DictionaryEntry.cpp
  compiler/ast/DictionaryEntry.h
  compiler/ast/DictionaryInitializer.cpp
  compiler/ast/DictionaryInitializer.h
  compiler/ast/ElvisOperator.cpp
  compiler/ast/ElvisOperator.h
  compiler/ast/Expression.cpp
  compiler/ast/Expression.h
  compiler/ast/FloatValue.cpp
  compiler/ast/FloatValue.h
  compiler/ast/Function.cpp
  compiler/ast/Function.h
  compiler/ast/FunctionCall.cpp
  compiler/ast/FunctionCall.h
  compiler/ast/FunctionParameterDeclaration.cpp
  compiler/ast/FunctionParameterDeclaration.h
  compiler/ast/FunctionParameterList.cpp
  compiler/ast/FunctionParameterList.h
  compiler/ast/Identifier.cpp
  compiler/ast/Identifier.h
  compiler/ast/IntegerValue.cpp
  compiler/ast/IntegerValue.h
  compiler/ast/ModuleFunctionDeclaration.cpp
  compiler/ast/ModuleFunctionDeclaration.h
  compiler/ast/Node.cpp
  compiler/ast/Node.h
  compiler/ast/NodeVisitor.cpp
  compiler/ast/NodeVisitor.h
  compiler/ast/Statement.cpp
  compiler/ast/Statement.h
  compiler/ast/StringValue.cpp
  compiler/ast/StringValue.h
  compiler/ast/StructInitializer.cpp
  compiler/ast/StructInitializer.h
  compiler/ast/StructMemberInitializer.cpp
  compiler/ast/StructMemberInitializer.h
  compiler/ast/TopLevelStatements.cpp
  compiler/ast/TopLevelStatements.h
  compiler/ast/UnaryOperator.cpp
  compiler/ast/UnaryOperator.h
  compiler/ast/Value.cpp
  compiler/ast/Value.h
  compiler/ast/ValueConsumer.cpp
  compiler/ast/ValueConsumer.h
  compiler/ast/VarStatement.cpp
  compiler/ast/VarStatement.h
  compiler/astbuilder/BuilderWorkspace.cpp
  compiler/astbuilder/BuilderWorkspace.h
  compiler/astbuilder/CompilerWorkspaceBuilder.cpp
  compiler/astbuilder/CompilerWorkspaceBuilder.h
  compiler/astbuilder/CompoundStatementBuilder.cpp
  compiler/astbuilder/CompoundStatementBuilder.h
  compiler/astbuilder/ExpressionBuilder.cpp
  compiler/astbuilder/ExpressionBuilder.h
  compiler/astbuilder/ModuleDeclarationBuilder.cpp
  compiler/astbuilder/ModuleDeclarationBuilder.h
  compiler/astbuilder/FunctionResolver.cpp
  compiler/astbuilder/FunctionResolver.h
  compiler/astbuilder/ModuleProcessor.cpp
  compiler/astbuilder/ModuleProcessor.h
  compiler/astbuilder/ProgramBuilder.cpp
  compiler/astbuilder/ProgramBuilder.h
  compiler/astbuilder/SimpleStatementBuilder.cpp
  compiler/astbuilder/SimpleStatementBuilder.h
  compiler/astbuilder/SourceFileProcessor.cpp
  compiler/astbuilder/SourceFileProcessor.h
  compiler/astbuilder/TreeBuilder.cpp
  compiler/astbuilder/TreeBuilder.h
  compiler/astbuilder/UserFunctionBuilder.cpp
  compiler/astbuilder/UserFunctionBuilder.h
  compiler/astbuilder/ValueBuilder.cpp
  compiler/astbuilder/ValueBuilder.h
  compiler/codegen/CodeEmitter.cpp
  compiler/codegen/CodeEmitter.h
  compiler/codegen/CodeGenerator.cpp
  compiler/codegen/CodeGenerator.h
  compiler/codegen/DataEmitter.cpp
  compiler/codegen/DataEmitter.h
  compiler/codegen/InstructionEmitter.cpp
  compiler/codegen/InstructionEmitter.h
  compiler/codegen/InstructionGenerator.cpp
  compiler/codegen/InstructionGenerator.h
  compiler/codegen/ModuleDeclarationRegistrar.cpp
  compiler/codegen/ModuleDeclarationRegistrar.h
  compiler/file/ConformingCharStream.cpp
  compiler/file/ConformingCharStream.h
  compiler/file/ErrorListener.cpp
  compiler/file/ErrorListener.h
  compiler/file/SourceFile.cpp
  compiler/file/SourceFile.h
  compiler/file/SourceFileCache.cpp
  compiler/file/SourceFileCache.h
  compiler/file/SourceFileIdentifier.cpp
  compiler/file/SourceFileIdentifier.h
  compiler/file/SourceLocation.cpp
  compiler/file/SourceLocation.h
  compiler/format/CompiledScriptSerializer.cpp
  compiler/format/CompiledScriptSerializer.h
  compiler/format/ListingWriter.cpp
  compiler/format/ListingWriter.h
  compiler/format/StoredTokenDecoder.cpp
  compiler/format/StoredTokenDecoder.h
  compiler/model/CompilerWorkspace.cpp
  compiler/model/CompilerWorkspace.h
  compiler/model/FunctionLink.cpp
  compiler/model/FunctionLink.h
  compiler/optimizer/Optimizer.cpp
  compiler/optimizer/Optimizer.h
  compiler/representation/CompiledScript.cpp
  compiler/representation/CompiledScript.h
  compiler/representation/ExportedFunction.cpp
  compiler/representation/ExportedFunction.h
  compiler/representation/ModuleDescriptor.cpp
  compiler/representation/ModuleDescriptor.h
  compiler/representation/ModuleFunctionDescriptor.cpp
  compiler/representation/ModuleFunctionDescriptor.h
  compiler/Profile.h
  compiler/Report.cpp
  compiler/Report.h
  berror.cpp
  berror.h
  blong.cpp 
  bobject.h
  bstruct.cpp
  bstruct.h
  compctx.cpp 
  compctx.h
  compiler.cpp
  compiler.h
  compilercfg.cpp 
  compilercfg.h
  compmodl.h
  config.h
  contiter.h
  dbl.cpp 
  dict.cpp 
  dict.h
  eprog.cpp
  eprog.h
  eprog2.cpp
  eprog3.cpp
  eprog_read.cpp
  escript.h
  escript_config.cpp
  escriptv.cpp
  escriptv.h
  escrutil.cpp
  escrutil.h
  execmodl.cpp
  execmodl.h
  exectype.h
  executor.cpp
  executor.h
  executortype.h
  expression.cpp
  expression.h
  filefmt.h
  fmodule.cpp
  fmodule.h
  impstr.h
  modules.h
  object.cpp 
  object.h
  objmembers.h
  objmethods.h
  objstrm.cpp
  operator.h
  options.h
  parser.cpp
  parser.h
  str.cpp 
  symcont.cpp
  symcont.h
  tkn_strm.cpp 
  token.cpp
  token.h
  tokens.cpp
  tokens.h
  userfunc.cpp
  userfunc.h
  verbtbl.h
)

