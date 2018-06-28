set(LLVM_LINK_COMPONENTS support)
  
add_clang_library(clangTidySmartContractSecurityModule
  OverflowCheck.cpp
  SmartContractSecurityTidyModule.cpp

  LINK_LIBS
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTidy
  clangTidyReadabilityModule
  clangTidyUtils
  clangTooling
  )
