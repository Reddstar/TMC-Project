
PRINT("DIRECTORY: ${SigaliResolver_mem}")
SET(PREFIX SigaliResolverMem_)
SET(DIRS export)
SETVARIABLES("${DIRS}" ${SigaliResolver_mem} ${PREFIX} SigaliResolver_mem )
DeclareComponents("${DIRS}" ${PREFIX})
