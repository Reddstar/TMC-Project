
project(SIGALI_MEM_RESOLVER)
cmake_minimum_required(VERSION 2.6)

MESSAGE(" ----- MEM RESOLVER ------")

SET(X ${SigaliResolverMem_export}/memint.h ${SigaliResolverMem_export}/memuser.h)
SET_SOURCE_FILES_PROPERTIES(${X} PROPERTIES GENERATED true)
COPY_FILE(${SigaliPackageMem_export} ${SigaliResolverMem_export} memint.h)
COPY_FILE(${SigaliPackageMem_export} ${SigaliResolverMem_export} memuser.h)

SET(LIBNAME memResolver)
SET(MOD_LIST ${SigaliPackage_mem}/memrec.c ${SigaliPackage_mem}/memblock.c)

SET_SOURCE_FILES_PROPERTIES(${MOD_LIST} PROPERTIES LANGUAGE CXX)
# adding some dependencies.
SET_SOURCE_FILES_PROPERTIES(${MOD_LIST} PROPERTIES OBJECT_DEPENDS "${X}")

INCLUDE_DIRECTORIES( ${SigaliPackage_mem} ${SigaliPackageHost_export}  ${SigaliPackageHost_import} ${SigaliResolverMem_export})
SET(LIBRARY_OUTPUT_PATH ${SigaliResolver_export})
ADD_LIBRARY(${LIBNAME} ${MOD_LIST})
#PK_ADD_STD_PROPERTIES(${LIBNAME})
MESSAGE(" ----- MEM RESOLVER -- END------")
