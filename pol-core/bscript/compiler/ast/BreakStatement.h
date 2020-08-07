#ifndef POLSERVER_BREAKSTATEMENT_H
#define POLSERVER_BREAKSTATEMENT_H

#include "JumpStatement.h"

namespace Pol::Bscript::Compiler
{
class BreakStatement : public JumpStatement
{
public:
  BreakStatement( const SourceLocation&, std::string label );

  void accept( NodeVisitor& visitor ) override;
  void describe_to( fmt::Writer& ) const override;
};

}  // namespace Pol::Bscript::Compiler

#endif  // POLSERVER_BREAKSTATEMENT_H
