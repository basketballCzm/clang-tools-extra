//===--- StringtosymbolCheck.cpp - clang-tidy------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "StringtosymbolCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace smartcontractsecurity {

void StringtosymbolCheck::registerMatchers(MatchFinder *Finder) {
  // FIXME: Add matchers.
  Finder->addMatcher(functionDecl().bind("x"), this);
}

void StringtosymbolCheck::check(const MatchFinder::MatchResult &Result) {
  // FIXME: Add callback implementation.
  const auto *MatchedDecl = Result.Nodes.getNodeAs<FunctionDecl>("x");
  if (MatchedDecl->getName().startswith("awesome_"))
    return;
  diag(MatchedDecl->getLocation(), "function %0 is insufficiently awesome")
      << MatchedDecl
      << FixItHint::CreateInsertion(MatchedDecl->getLocation(), "awesome_");
}

} // namespace smartcontractsecurity
} // namespace tidy
} // namespace clang
