
# Sigali Tool.
# -----------

project(Sigali)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Environment 
IF(NOT DEFINED pKMacros_FOUND)
  IF(NOT EXISTS "$ENV{Sigali_root}")
    MESSAGE("============================================================================")
    MESSAGE("        The variable Sigali_root is not defined...fixing it")
    MESSAGE("============================================================================")
    SET(ENV{Sigali_root} ${CMAKE_CURRENT_SOURCE_DIR})
    MESSAGE( "------------> ${CMAKE_CURRENT_SOURCE_DIR}")
    SET(PKCONFIG TRUE)
  ELSE(NOT EXISTS "$ENV{Sigali_root}")
    SET(PKCONFIG FALSE)
  ENDIF(NOT EXISTS "$ENV{Sigali_root}")

  FILE(TO_CMAKE_PATH "$ENV{Sigali_root}" Sigali_root)
  SET(CMAKE_MODULE_PATH "${Sigali_root}/CMakeModules")
  FIND_PACKAGE(pKMacros REQUIRED)
ENDIF(NOT DEFINED pKMacros_FOUND)

LOAD_ENV()
GEN_BOOT_SOFT()

MESSAGE(">>>>>> STARTING CMAKE for  ${PROJECT_NAME}, SIGALI SOURCE AVAILABLE = ${SIGALI_ALL}")

DECLARECOMPONENT(${Sigali_bin})

IF(SIGALI_ALL)
  DECLARECOMPONENT(${Sigali_package})
ENDIF(SIGALI_ALL)

DECLARECOMPONENT(${Sigali_Synthesis})

IF(SIGALI_ALL)
  pK_ADD_SUBDIRECTORY(${Sigali_package})
ENDIF(SIGALI_ALL)
