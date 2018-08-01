#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "MultiindexfindCheck.h"
#include "OverflowCheck.h"
#include "StringtosymbolCheck.h"

namespace clang {
namespace tidy {
namespace smartcontractsecurity {

class SmartContractSecurityModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<MultiindexfindCheck>(
        "smartcontractsecurity-multiIndexFind");
    CheckFactories.registerCheck<OverflowCheck>(
        "smartcontractsecurity-overflow");
    CheckFactories.registerCheck<OverflowCheck>(
        "smartcontractsecurity-stringtosymbol");
	}
};

// Register the SmartContractSecurityModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<SmartContractSecurityModule>
    X("smartcontractsecurity-module", "Adds smartcontractsecurity-related checks.");

} // namespace smartcontractsecurity

// This anchor is used to force the linker to link in the generated object file
// and thus register the SmartContractSecurityModule.
volatile int SmartContractSecurityModuleAnchorSource = 0;

} // namespace tidy
} // namespace clang
