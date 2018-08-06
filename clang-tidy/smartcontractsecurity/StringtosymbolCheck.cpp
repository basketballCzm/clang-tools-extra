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
	Finder->addMatcher(callExpr(callee(functionDecl(hasAnyName("string_to_symbol")))).bind("function"),this);
}

void StringtosymbolCheck::check(const MatchFinder::MatchResult &Result) {
// FIXME: Add callback implementation.
  const auto *MatchedDecl = Result.Nodes.getNodeAs<CallExpr>("function");
  if (MatchedDecl)
  	diag(MatchedDecl->getLocStart(), "Make sure the token name size is checked before calling the string_to_symbol function")
      << FixItHint::CreateInsertion(MatchedDecl->getLocStart(), "eosio_assert(symbolname.size() <= 255)");
}


} // namespace smartcontractsecurity
} // namespace tidy
} // namespace clang
