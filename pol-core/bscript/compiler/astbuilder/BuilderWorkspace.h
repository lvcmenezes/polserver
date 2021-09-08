#ifndef POLSERVER_BUILDERWORKSPACE_H
#define POLSERVER_BUILDERWORKSPACE_H

#include <map>
#include <memory>
#include <string>

#include "bscript/compiler/astbuilder/FunctionResolver.h"

namespace Pol::Bscript::Compiler
{
class CompilerWorkspace;
class Profile;
class Report;
class SourceFile;
class SourceFileCache;
class SourceFileIdentifier;
class Statement;

class BuilderWorkspace
{
public:
  BuilderWorkspace( CompilerWorkspace&, SourceFileCache& em_cache, SourceFileCache& inc_cache,
                    Profile& profile, Report& report, bool is_diagnostics_mode );
  ~BuilderWorkspace();

  CompilerWorkspace& compiler_workspace;

  SourceFileCache& em_cache;
  SourceFileCache& inc_cache;

  Profile& profile;
  Report& report;

  std::map<std::string, std::shared_ptr<SourceFile>> source_files;
  FunctionResolver function_resolver;
  const bool is_diagnostics_mode;
};

}  // namespace Pol::Bscript::Compiler

#endif  // POLSERVER_BUILDERWORKSPACE_H
