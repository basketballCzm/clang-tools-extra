#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "OverflowCheck.h"

namespace clang {
namespace tidy {
namespace smartcontractsecurity {

class SmartContractSecurityModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<OverflowCheck>(
        "smartcontractsecurity-overflow");
};

// Register the ReadabilityModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<ReadabilityModule>
    X("smartcontractsecurity-module", "Adds smartcontractsecurity-related checks.");

} // namespace smartcontractsecurity

// This anchor is used to force the linker to link in the generated object file
// and thus register the ReadabilityModule.
volatile int SmartContractSecurityModuleAnchorSource = 0;

} // namespace tidy
} // namespace clang
