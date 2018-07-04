
project(SIGALI_RESOLVER_TDD)
cmake_minimum_required(VERSION 2.6)

MESSAGE( " ----- TDD RESOLVER ------")

SET(LIBNAME tddResolver)
SET(MOD_LIST 
  # imported
  ${SigaliPackage_tdd}/tddassoc.c
  ${SigaliPackage_tdd}/tddcache.c 
  #${SigaliPackage_tdd}/tddcache4.c 
  ${SigaliPackage_tdd}/tdderror.c
  ${SigaliPackage_tdd}/tddtable.c
  ${SigaliPackage_tdd}/tdd.c
  # local
  ${SigaliResolver_tdd}/tdd_redefined.c 
  ${SigaliResolver_tdd}/tddundump.c
  ${SigaliResolver_tdd}/tddmanager_re.c
  ${SigaliResolver_tdd}/tddresolve_re.c
  )
 
SET(X  ${SigaliPackageTdd_export}/tddint.h)
SET_SOURCE_FILES_PROPERTIES(${SigaliResolver_tdd}/tdd_redefined.c ${SigaliResolver_tdd}/tdd_redefined.c  ${SigaliResolver_tdd}/tddresolve_re.c ${SigaliResolver_tdd}/tddundump.c 
  PROPERTIES OBJECT_DEPENDS  "${X}")
SET_SOURCE_FILES_PROPERTIES(${MOD_LIST} PROPERTIES LANGUAGE CXX)
INCLUDE_DIRECTORIES( ${SigaliResolver_tdd} ${SigaliResolverTdd_export} ${SigaliPackage_tdd} ${SigaliPackageTdd_export} ${SigaliResolverMem_export} ${SigaliPackageHost_import} ${SigaliPackageHost_export})
SET(LIBRARY_OUTPUT_PATH ${SigaliResolver_export})
ADD_LIBRARY(${LIBNAME} ${MOD_LIST})
#PK_ADD_STD_PROPERTIES(${LIBNAME})

MESSAGE( " ----- TDD RESOLVER -- END------")



