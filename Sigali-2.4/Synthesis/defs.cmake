
PRINT("DIRECTORY: ${Sigali_Synthesis}")
SET(PREFIX SigaliSynthesis_)
SET(DIRS Demos resolver)
SETVARIABLES("${DIRS}" ${Sigali_Synthesis} ${PREFIX} Sigali_Synthesis )
DeclareComponents("${DIRS}" ${PREFIX})
