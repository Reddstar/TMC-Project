
PRINT("DIRECTORY: ${SigaliResolver_res}")
SET(PREFIX SigaliResolverRes_)
SET(DIRS export)
SETVARIABLES("${DIRS}" ${SigaliResolver_res} ${PREFIX} SigaliResolver_res  )
DeclareComponents("${DIRS}" ${PREFIX})
