set(LLVM_LINK_COMPONENTS support)
  
add_clang_library(clangTidySmartContractSecurityModule
  FreezepermissionCheck.cpp
  MultiindexfindCheck.cpp
  OverflowCheck.cpp
  SmartContractSecurityTidyModule.cpp
  StringtosymbolCheck.cpp

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
