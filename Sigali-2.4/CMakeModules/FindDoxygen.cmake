#/***Polychrony License******************************************
# *                                                             *
# * Copyright: IRISA/INRIA Rennes - ESPRESSO team.              *
# * This software is under the terms of the CeCILL-B License.   *
# * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html *
# *                                                             *
# ***************************************************************/

# -------------------------------------------------------------------
# set of CMAKE Macros for Polychrony environment
# Author: Loïc Besnard 
# Email: Loic.Besnard@irisa.fr
# -------------------------------------------------------------------

FIND_PROGRAM(DOXYGEN_EXECUTABLE
  NAMES doxygen
  DOC "where is the doxygen executable?"
  PATHS 
  $ENV{DOXYGEN_HOME}
  )

FIND_PROGRAM(DOXYGEN_DOT_EXECUTABLE
  NAMES dot
  DOC "where is dot executable from Graphiz (for doxygen)?"
  PATHS  
  $ENV{DOT_HOME}
  )

IF (DOXYGEN_EXECUTABLE)
  SET (DOXYGEN_FOUND TRUE)
  SET (DOXYGEN ${DOXYGEN_EXECUTABLE})  # deprecated
ENDIF (DOXYGEN_EXECUTABLE)

IF (DOXYGEN_DOT_EXECUTABLE)
  SET (DOXYGEN_DOT_FOUND TRUE)  
  # the directory of dot is required in doxygen.config: DOT_PATH
  GET_FILENAME_COMPONENT (DOXYGEN_DOT_EXECUTABLE_PATH ${DOXYGEN_DOT_EXECUTABLE} PATH)
  SET (DOT ${DOXYGEN_DOT_EXECUTABLE})   # deprecated
ENDIF (DOXYGEN_DOT_EXECUTABLE)

MARK_AS_ADVANCED(
  DOXYGEN_EXECUTABLE
  DOXYGEN_DOT_EXECUTABLE
  DOXYGEN_DOT_EXECUTABLE_PATH
  )

MACRO(COPYDOC INPUT OUTPUT)
  ADD_CUSTOM_COMMAND(
    OUTPUT ${OUTPUT}
    COMMAND ${CMAKE_COMMAND} -E echo_append "Copying...${OUTPUT}"
    COMMAND ${CMAKE_COMMAND} -E copy ${INPUT} ${OUTPUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS ${INPUT}
    )
ENDMACRO(COPYDOC INPUT OUTPUT)


MACRO(MAKEDOC  DOXYGEN_INPUT1 DOXYGEN_OUTPUT1 DEP_LIST)
  ADD_CUSTOM_COMMAND(
    OUTPUT ${DOXYGEN_OUTPUT1}
    COMMAND ${CMAKE_COMMAND} -E echo "Building API Documentation...${DOXYGEN_OUTPUT1}"
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT1}
    COMMAND ${CMAKE_COMMAND} -E echo "Done."
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS ${DEP_LIST}
    )
ENDMACRO(MAKEDOC  DOXYGEN_INPUT1 DOXYGEN_OUTPUT1 DEP_LIST)


MACRO(MAKE_DOC_TARGET DOXYGEN_INPUT DOXYGEN_OUTPUT DEP_LIST)
  IF (DOXYGEN_FOUND)
    PRINT( "DOXYGEN binary is : ${DOXYGEN_EXECUTABLE}")
    MAKEDOC( ${DOXYGEN_INPUT} ${DOXYGEN_OUTPUT} "${DEP_LIST}")
    ADD_CUSTOM_TARGET(doc DEPENDS ${DOXYGEN_OUTPUT})
    
    ADD_CUSTOM_TARGET(doc_forced
      COMMAND ${CMAKE_COMMAND} -E echo "Building API Documentation..."
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
      COMMAND ${CMAKE_COMMAND} -E echo "Done."
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      )
  ELSE(DOXYGEN_FOUND)
    MESSAGE("Doxygen package not found.")
  ENDIF (DOXYGEN_FOUND)
ENDMACRO(MAKE_DOC_TARGET DOXYGEN_INPUT DOXYGEN_OUTPUT DEP_LIST)

