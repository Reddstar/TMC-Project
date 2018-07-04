
PRINT("Variable: ${Sigali_root}")
SET(PREFIX Sigali_)
FILE(MAKE_DIRECTORY  ${Sigali_root}/com)
SET(DIRS com doc examples Export lib package Synthesis bin)
SETVARIABLES("${DIRS}" ${Sigali_root} ${PREFIX} Sigali_root)

IF(PKCONFIG)
  GEN_CMD_ECHO (${Sigali_com} echoInf INFO 1)
  GEN_CMD_ECHO (${Sigali_com} echoErr ERROR 0)
  GEN_CMD_ECHO (${Sigali_com} echoWar WARNING 0)
  
  # NOT EFFECT WHEN THE SOURCE IS NOT EXPORTED.
  IF(SIGALI_ALL)
    GEN_INSTALL_SCRIPT()    # Generate the script _install_
  ENDIF(SIGALI_ALL)
ENDIF(PKCONFIG)
