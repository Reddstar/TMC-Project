# -------------------------------------------------------------------
# set of CMAKE Macros for Sigali environment
# Author: Loïc Besnard 
# Email: Loic.Besnard@irisa.fr
# -------------------------------------------------------------------
# SYNOPSIS
#    cmake <path-to-source> [-DDEBUG_MODE=1]
# -------------------------------------------------------------------

SET(CURRENT_VERSION "2.3")
SET(pkEnvFile sigaliEnv)
SET(pKMacros_FOUND TRUE)
#SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_VERBOSE_MAKEFILE ON)

#
# doc, doc_forced are used in sub-directories. (see cmake --help-policy CMP0002)
# But for windows, it is necessary to call cmake with the option -G "NMake Makefiles"
# ----------------------------------------------------------------------------------
SET_PROPERTY(GLOBAL PROPERTY ALLOW_DUPLICATE_CUSTOM_TARGETS 1)

# Useful for the ADD_SUBDIRECTORY() command. The files will be generated in the cmake/CMakeFiles directory,
# not in the cmake root.
#SET(CMAKE_FILES_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY})

INCLUDE(${CMAKE_MODULE_PATH}/LIB.cmake)

MACRO(SET_CPP_SYMBOLS)
  ADD_DEFINITIONS( -D_VIRTUAL_=)
  ADD_DEFINITIONS( -D_PROTECTED_= )
  ADD_DEFINITIONS( -D_PUBLIC_= )
  ADD_DEFINITIONS( -D_PRIVATE_= )
  ADD_DEFINITIONS( -D_INIT_=: )
  ADD_DEFINITIONS( -D_ENDINIT_= )
  SET_ARCHI()
ENDMACRO(SET_CPP_SYMBOLS)


MACRO(SET_C_CPP_DEFS)
  SET(CPP_FLAGS) 
  if( UNIX )
    SET(CPP_FLAGS "-w -g -fPIC ")
    # ADD_DEFINITIONS( -pedantic )
  else(UNIX)
    if (MSVC)
      SET(CPP_FLAGS "/nologo /c /MD /W3 /Gm /GX /ZI /Od /YX /GZ")
      ADD_DEFINITIONS(/DWIN32)
      ADD_DEFINITIONS(/D_DEBUG)
      ADD_DEFINITIONS(/D_MBCS)
      ADD_DEFINITIONS(/D_LIB)
      ADD_DEFINITIONS(/D__STDC__)
    ENDIF( MSVC )
  ENDIF( UNIX )
ENDMACRO(SET_C_CPP_DEFS)

MACRO(SETXKROOT)
  FILE(TO_CMAKE_PATH "$ENV{Sigali_root}" Sigali_root)
ENDMACRO(SETXKROOT)

MACRO(PK_ADD_STD_PROPERTIES TARGET)
  SET_TARGET_PROPERTIES(${TARGET} PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})
  EXPORT(TARGETS ${TARGET} APPEND FILE "${Sigali_root}/CMakeModules/FuncExport.cmake")
ENDMACRO(PK_ADD_STD_PROPERTIES TARGET)

MACRO(SET_SIGALI_ALL)
  SET(NAME ${Sigali_root}/package)
  IF(EXISTS ${NAME})
    SET(SIGALI_ALL TRUE)
  ELSE(EXISTS ${NAME})
    SET(SIGALI_ALL FALSE)
  ENDIF(EXISTS ${NAME})
ENDMACRO(SET_SIGALI_ALL)

MACRO(LOAD_ENV)
  PRINT("C_COMPILER = ${CMAKE_C_COMPILER}")
  PRINT("CPP_COMPILER = ${CMAKE_CXX_COMPILER}")
  PRINT("CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
  SET_SHELL_DEFS()
  SETXKROOT()
  INCLUDE(${Sigali_root}/defs.cmake)
  SET_CMAKE_PARAMETERS()
  SET_C_CPP_DEFS()
  SET_HOST_DEFS()
  SETLITTLEENDIAN()
  SET_CPP_SYMBOLS()
  SET_SIGALI_ALL()
ENDMACRO(LOAD_ENV)

MACRO(GEN_BOOT_SOFT)
  MK_CONFIG_NAME(${pkEnvFile} NAME_FILE_CONFIG)
  IF (PKCONFIG)
    FILE(REMOVE ${NAME_FILE_CONFIG})
  ENDIF (PKCONFIG)

  IF(NOT EXISTS ${NAME_FILE_CONFIG})
    BEGIN_CONFIG_FILE(${NAME_FILE_CONFIG})
    MK_SYSTEM_PATH("$ENV{Sigali_root}" XX)
    ADD_SHELL_VAR(${NAME_FILE_CONFIG} Sigali_root "${XX}" "")
    ADD_SHELL_VAR(${NAME_FILE_CONFIG} Sigali_VERSION ${CURRENT_VERSION} "")
    ADD_LOAD_SETENV(${NAME_FILE_CONFIG} Sigali_root)
    IF(UNIX)
      FILE(APPEND ${NAME_FILE_CONFIG} "if ( ! \$?SIGALI_PATH ) setenv SIGALI_PATH \"\" \n")
      FILE(APPEND ${NAME_FILE_CONFIG} "setenv SIGALI_PATH \".:\${Sigali_root}/lib:\${SIGALI_PATH}\" \n ")
      FILE(APPEND ${NAME_FILE_CONFIG} "alias sigali '\${Sigali_bin}/sigali' \n ")
      FILE(APPEND ${NAME_FILE_CONFIG} " echo \"-----------------------------------------------------------------------------\"\n")
      FILE(APPEND ${NAME_FILE_CONFIG} "echo \" >>>> sigali command is available.\"\n")
      FILE(APPEND ${NAME_FILE_CONFIG} "echo \" >>>> SIGALI Documentation is available in : \${Sigali_doc} directory \"\n")
      FILE(APPEND ${NAME_FILE_CONFIG} "echo \" >>>> Predefined SIGALI Libraries are available in : \${Sigali_lib} directory \"\n")
      FILE(APPEND ${NAME_FILE_CONFIG} "echo \"------------------------------------------------------------------------------\"\n")
    ELSE(UNIX)
    
    ENDIF(UNIX)
  ENDIF(NOT EXISTS ${NAME_FILE_CONFIG})
  
ENDMACRO(GEN_BOOT_SOFT)




