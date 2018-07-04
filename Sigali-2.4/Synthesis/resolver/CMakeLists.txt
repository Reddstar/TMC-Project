

project(SIGALI_RESOLVER)
cmake_minimum_required(VERSION 2.6)

FILE(TO_CMAKE_PATH "$ENV{Sigali_root}" Sigali_root)
SET(CMAKE_MODULE_PATH "${Sigali_root}/CMakeModules")
FIND_PACKAGE(pKMacros REQUIRED)
LOAD_ENV()

DeclareComponent(${Sigali_root})
DeclareComponent(${Sigali_Synthesis})
IF(SIGALI_ALL)
  DECLARECOMPONENT(${SigaliResolver_mem})
  DECLARECOMPONENT(${SigaliResolver_res})
  DECLARECOMPONENT(${SigaliResolver_tdd})

  pK_ADD_SUBDIRECTORY(${SigaliResolver_mem})
  pK_ADD_SUBDIRECTORY(${SigaliResolver_res})
  pK_ADD_SUBDIRECTORY(${SigaliResolver_tdd})
  
  
  SET(HEADERS
    ${SigaliResolver_export}/integer.h
    ${SigaliResolver_export}/pointer.h
    ${SigaliResolver_export}/memint.h
    ${SigaliResolver_export}/memuser.h
    ${SigaliResolver_export}/configuration.h 
    ${SigaliResolver_export}/equation.h
    ${SigaliResolver_export}/fonction.h
    ${SigaliResolver_export}/resolveur.h
    ${SigaliResolver_export}/variable.h
    ${SigaliResolver_export}/tddresolv.h
    ${SigaliResolver_export}/tddint.h
    ${SigaliResolver_export}/tdduser.h
    ${SigaliResolver_export}/z3z.h
    )
  
  SET_SOURCE_FILES_PROPERTIES(${HEADERS} PROPERTIES GENERATED true)
  ADD_CUSTOM_TARGET(exportResolver ALL DEPENDS ${HEADERS}
    )

  COPY_FILE(${SigaliPackageHost_import} ${SigaliResolver_export} integer.h)
  COPY_FILE(${SigaliPackageHost_import} ${SigaliResolver_export} pointer.h)
  COPY_FILE(${SigaliResolverMem_export} ${SigaliResolver_export} memint.h)
  COPY_FILE(${SigaliResolverMem_export} ${SigaliResolver_export} memuser.h)
  COPY_FILE(${SigaliResolverRes_export} ${SigaliResolver_export} configuration.h)
  COPY_FILE(${SigaliResolverRes_export} ${SigaliResolver_export} equation.h)
  COPY_FILE(${SigaliResolverRes_export} ${SigaliResolver_export} fonction.h)
  COPY_FILE(${SigaliResolverRes_export} ${SigaliResolver_export} resolveur.h)
  COPY_FILE(${SigaliResolverRes_export} ${SigaliResolver_export} variable.h)
  COPY_FILE(${SigaliResolverRes_export} ${SigaliResolver_export} z3z.h)
  COPY_FILE(${SigaliResolverTdd_export} ${SigaliResolver_export} tddresolv.h)
  COPY_FILE(${SigaliPackageTdd_export}  ${SigaliResolver_export} tddint.h)
  COPY_FILE(${SigaliPackageTdd_export}  ${SigaliResolver_export} tdduser.h)
  
ENDIF(SIGALI_ALL)
