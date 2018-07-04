

project(SIGALI_SYNTHESIS)
cmake_minimum_required(VERSION 2.6)

FILE(TO_CMAKE_PATH "$ENV{Sigali_root}" Sigali_root)
SET(CMAKE_MODULE_PATH "${Sigali_root}/CMakeModules")
FIND_PACKAGE(pKMacros REQUIRED)
LOAD_ENV()

MESSAGE("SIGALI_SYNTHESIS: ${Sigali_Synthesis}")
DeclareComponent(${Sigali_root})

IF(SIGALI_ALL)
  DeclareComponent(${Sigali_package})
  DeclareComponent(${SigaliPackage_host})
ENDIF(SIGALI_ALL)

DeclareComponent(${Sigali_Synthesis})
DeclareComponent(${SigaliSynthesis_resolver})

pK_ADD_SUBDIRECTORY(${SigaliSynthesis_resolver})

