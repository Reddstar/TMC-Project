
project(SIGALI_RESOLVER_TDD)
cmake_minimum_required(VERSION 2.6)

MESSAGE( " ----- RESOLVER ------")

SET(LIBNAME resResolver)
SET(MOD_LIST 
  ${SigaliResolver_res}/equation.c
  ${SigaliResolver_res}/configuration.c 
  ${SigaliResolver_res}/fonction.c
  ${SigaliResolver_res}/resolveur.c
  ${SigaliResolver_res}/variable.c
  ${SigaliResolver_res}/z3z.c  
  )

SET(X ${SigaliResolverRes_export}/equation.h ${SigaliResolverRes_export}/fonction.h ${SigaliResolverRes_export}/configuration.h)
SET_SOURCE_FILES_PROPERTIES( ${SigaliResolver_res}/configuration.c PROPERTIES OBJECT_DEPENDS "${X}")

SET(X ${SigaliResolverRes_export}/equation.h ${SigaliResolver_res}/random.c)
SET_SOURCE_FILES_PROPERTIES( ${SigaliResolver_res}/equation.c PROPERTIES OBJECT_DEPENDS "${X}")

SET(X ${SigaliResolverRes_export}/fonction.h ${SigaliResolverRes_export}/variable.h)
SET_SOURCE_FILES_PROPERTIES( ${SigaliResolver_res}/fonction.c PROPERTIES OBJECT_DEPENDS "${X}")

SET(X ${SigaliResolverRes_export}/resolveur.h ${SigaliResolverRes_export}/configuration.h)
SET_SOURCE_FILES_PROPERTIES( ${SigaliResolver_res}/resolveur.c PROPERTIES OBJECT_DEPENDS "${X}")

SET(X ${SigaliResolverRes_export}/variable.h )
SET_SOURCE_FILES_PROPERTIES( ${SigaliResolver_res}/variable.c PROPERTIES OBJECT_DEPENDS "${X}")

SET(X ${SigaliResolverRes_export}/z3z.h )
SET_SOURCE_FILES_PROPERTIES( ${SigaliResolver_res}/z3z.c PROPERTIES OBJECT_DEPENDS "${X}")


SET_SOURCE_FILES_PROPERTIES(${MOD_LIST} PROPERTIES LANGUAGE CXX)
#INCLUDE_DIRECTORIES( ${SigaliResolver_tdd} ${SigaliPackage_tdd} ${SigaliResolverTdd_export} ${SigaliPackageTdd_export} ${SigaliResolverMem_export} ${SigaliPackageHost_import} ${SigaliPackageHost_export})

INCLUDE_DIRECTORIES( ${SigaliResolverRes_export} ${SigaliResolver_res} ${SigaliPackageHost_import} ${SigaliPackageHost_export} ${SigaliResolverMem_export})
SET(LIBRARY_OUTPUT_PATH ${SigaliResolver_export})
ADD_LIBRARY(${LIBNAME} ${MOD_LIST})
#PK_ADD_STD_PROPERTIES(${LIBNAME})

MESSAGE( " ----- RESOLVER -- END------")



