//===--- FreezepermissionCheck.h - clang-tidy--------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_SMARTCONTRACTSECURITY_FREEZEPERMISSIONCHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_SMARTCONTRACTSECURITY_FREEZEPERMISSIONCHECK_H

#include "../ClangTidy.h"

namespace clang {
namespace tidy {
namespace smartcontractsecurity {

/// FIXME: Write a short description.
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/smartcontractsecurity-freezepermission.html
class FreezepermissionCheck : public ClangTidyCheck {
public:
  FreezepermissionCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context){flag_freeze = false;}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
private:
  bool flag_freeze;
};

} // namespace smartcontractsecurity
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_SMARTCONTRACTSECURITY_FREEZEPERMISSIONCHECK_H
