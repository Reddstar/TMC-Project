
PRINT("DIRECTORY: ${SigaliSynthesis_resolver}")
SET(PREFIX SigaliResolver_)
SET(DIRS tdd mem export res )
SETVARIABLES("${DIRS}" ${SigaliSynthesis_resolver} ${PREFIX} SigaliSynthesis_resolver )
DeclareComponents("${DIRS}" ${PREFIX})

# Generating the makeresolver command.
IF(SIGALI_ALL)
  IF(PKCONFIG)
    MK_CONFIG_NAME(_config_ CONFIG_NAME)
    MK_CONFIG_NAME(makeResolver cmd)
    SET(OPTIONS clean all doc doc_forced)
    SET(DEFAULT_OPTIONS "all")
    SET(CONFIG_FILE ${Sigali_Synthesis}/${CONFIG_NAME})  
    IF(UNIX)
      GEN_ECHO_USE(${CONFIG_FILE} "${cmd}" "[clean, all, doc, doc_forced]" "to build a new Sigali/Resolver version")
      FILE(APPEND ${CONFIG_FILE} "alias ${cmd} '\${Sigali_Synthesis}/${cmd} \$*'\n ")
    ENDIF(UNIX)    
    
    SET(CONFIG_FILE ${Sigali_Synthesis}/${cmd})
    GEN_HEADER_SCRIPT(${CONFIG_FILE})
    GEN_REQUIRE_SHELL_VAR(${CONFIG_FILE} Sigali_root)
    GEN_REQUIRE_DIR(${CONFIG_FILE} Sigali_Synthesis)

    GEN_ARGUMENTS(${CONFIG_FILE} "${OPTIONS}" "${DEFAULT_OPTIONS}" ${cmd})
    GEN_CMAKE_CMD(${CONFIG_FILE} Sigali_Synthesis arguments)
    
  ENDIF(PKCONFIG)
ENDIF(SIGALI_ALL)
