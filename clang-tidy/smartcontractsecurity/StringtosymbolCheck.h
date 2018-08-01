//===--- StringtosymbolCheck.h - clang-tidy----------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_SMARTCONTRACTSECURITY_STRINGTOSYMBOLCHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_SMARTCONTRACTSECURITY_STRINGTOSYMBOLCHECK_H

#include "../ClangTidy.h"

namespace clang {
namespace tidy {
namespace smartcontractsecurity {

/// FIXME: Write a short description.
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/smartcontractsecurity-stringtosymbol.html
class StringtosymbolCheck : public ClangTidyCheck {
public:
  StringtosymbolCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace smartcontractsecurity
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_SMARTCONTRACTSECURITY_STRINGTOSYMBOLCHECK_H
