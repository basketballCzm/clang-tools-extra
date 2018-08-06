//===--- FreezepermissionCheck.cpp - clang-tidy----------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "FreezepermissionCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace smartcontractsecurity {


void FreezepermissionCheck::registerMatchers(MatchFinder *Finder) {
  // FIXME: Add matchers.
  Finder->addMatcher(functionDecl().bind("function"), this);
}

void FreezepermissionCheck::check(const MatchFinder::MatchResult &Result) {
  // FIXME: Add callback implementation.
  const auto *MatchedDecl = Result.Nodes.getNodeAs<FunctionDecl>("function");
  if (MatchedDecl->getNameAsString() == "freeze"){
  	flag_freeze = true;
  	diag(MatchedDecl->getLocation(), "Make sure you have a freeze status check in the freeze function.")
      << FixItHint::CreateInsertion(MatchedDecl->getLocation(), "eosio_assert(!st.is_frozen, \"issuer currnecy is frozen\");");
  	return;
  }
  if(flag_freeze && MatchedDecl->getName().startswith("issue")){
  	diag(MatchedDecl->getLocation(), "Make sure you have a freeze status check in the issue function.")
      << FixItHint::CreateInsertion(MatchedDecl->getLocation(), "eosio_assert(!st.is_frozen, \"issuer currnecy is frozen\");");
      return;
  }
  if(flag_freeze && MatchedDecl->getName().startswith("transfer")){
  	diag(MatchedDecl->getLocation(), "Make sure you have a freeze status check in the transfer function.")
      << FixItHint::CreateInsertion(MatchedDecl->getLocation(), "eosio_assert( !st.can_freeze || !from.frozen, \"account is frozen by issuer\" );");
      return;
  }

}

} // namespace smartcontractsecurity
} // namespace tidy
} // namespace clang
