
PRINT("DIRECTORY: ${SigaliResolver_tdd}")
SET(PREFIX SigaliResolverTdd_)
SET(DIRS export)
SETVARIABLES("${DIRS}" ${SigaliResolver_tdd} ${PREFIX} SigaliResolver_tdd )
DeclareComponents("${DIRS}" ${PREFIX})
