Set(SYSTEM_INCLUDE_DIRECTORIES
${SYSTEM_INCLUDE_DIRECTORIES}
${BASE_INCLUDE_DIRECTORIES}
)

set(INCLUDE_DIRECTORIES
#put here all directories where header files are located
${SFSROOT_SOURCE_DIR}/sfsbase
${SFSROOT_SOURCE_DIR}/sfsdata
#${SFSROOT_SOURCE_DIR}/sfsdata/wrData
${SFSROOT_SOURCE_DIR}/sfsdata/frsData
${SFSROOT_SOURCE_DIR}/sfsdata/germaniumData
#${SFSROOT_SOURCE_DIR}/sfsdata/aidaData
${SFSROOT_SOURCE_DIR}/sfsdata/bplastData
#${SFSROOT_SOURCE_DIR}/sfsdata/fatimaData
)

include_directories( ${INCLUDE_DIRECTORIES})
include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})

link_directories(${FAIRROOT_LIBRARY_DIR} ${ROOT_LIBRARY_DIR})

file(GLOB SRCS 
*.cxx 
)

# fill list of header files from list of source files
# by exchanging the file extension
CHANGE_FILE_EXTENSION(*.cxx *.h HEADERS "${SRCS}")
install(FILES "sfsLogger.h" DESTINATION include)

Set(LINKDEF BaseLinkDef.h)

Set(DEPENDENCIES
    GeoBase ParBase MbsAPI Base FairTools sfsData Core Geom GenVector Physics
    Matrix MathCore Hist Graf Gpad Net Imt RIO RHTTP Spectrum)

Set(LIBRARY_NAME sfsBase)

GENERATE_LIBRARY()

