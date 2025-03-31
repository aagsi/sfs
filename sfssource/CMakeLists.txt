set(SYSTEM_INCLUDE_DIRECTORIES
${SYSTEM_INCLUDE_DIRECTORIES}
${BASE_INCLUDE_DIRECTORIES}
${ucesb_INCLUDE_DIR}
)

set(INCLUDE_DIRECTORIES
#put here all directories where header files are located
${SFSROOT_SOURCE_DIR}/sfsbase
${SFSROOT_SOURCE_DIR}/sfssource
${SFSROOT_SOURCE_DIR}/sfssource/base
${SFSROOT_SOURCE_DIR}/sfssource/wr
${SFSROOT_SOURCE_DIR}/sfssource/frs
#${SFSROOT_SOURCE_DIR}/sfssource/lisa
#${SFSROOT_SOURCE_DIR}/sfssource/aida
#${SFSROOT_SOURCE_DIR}/sfssource/bplast
#${SFSROOT_SOURCE_DIR}/sfssource/fatima
#${SFSROOT_SOURCE_DIR}/sfssource/germanium
#${SFSROOT_SOURCE_DIR}/sfssource/bgo
#${SFSROOT_SOURCE_DIR}/sfssource/beammonitor
#${SFSROOT_SOURCE_DIR}/sfssource/bb7
#${SFSROOT_SOURCE_DIR}/sfssource/fimp
${SFSROOT_SOURCE_DIR}/sfsdata
${SFSROOT_SOURCE_DIR}/sfsdata/frsData
#${SFSROOT_SOURCE_DIR}/sfsdata/lisaData
#${SFSROOT_SOURCE_DIR}/sfsdata/bgoData
#${SFSROOT_SOURCE_DIR}/sfsdata/wrData
#${SFSROOT_SOURCE_DIR}/sfsdata/aidaData
#${SFSROOT_SOURCE_DIR}/sfsdata/bplastData
#${SFSROOT_SOURCE_DIR}/sfsdata/fatimaData
#${SFSROOT_SOURCE_DIR}/sfsdata/germaniumData
#${SFSROOT_SOURCE_DIR}/sfsdata/beammonitorData
#${SFSROOT_SOURCE_DIR}/sfsdata/timemachineData
#${SFSROOT_SOURCE_DIR}/sfsdata/bb7Data
#${SFSROOT_SOURCE_DIR}/sfsdata/fimpData
#${SFSROOT_SOURCE_DIR}/sfsdata/travMusData
${SFSROOT_SOURCE_DIR}/sfsdata/baseData
)

set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
${FAIRROOT_LIBRARY_DIR}
${ucesb_LIBRARY_DIR}
)

include_directories( ${INCLUDE_DIRECTORIES})
include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})
link_directories( ${LINK_DIRECTORIES})

set(SRCS
./base/UcesbSource.cxx
./base/UnpackReader.cxx
./base/sfsReader.cxx
./base/CorrelationsMap.cxx
./base/GainShift.cxx
#./aida/AidaReader.cxx
#./aida/AidaCal2Hit.cxx
#./aida/AidaUnpack2Cal.cxx
./frs/FrsReader.cxx
./frs/FrsRaw2Cal.cxx
./frs/FrsCal2Hit.cxx
#./travMus/TravMusReader.cxx
#./travMus/TravMusRaw2Cal.cxx
#./travMus/TravMusCal2Ana.cxx
#./germanium/GermaniumReader.cxx
#./lisa/LisaReader.cxx
#./lisa/LisaRaw2Cal.cxx
#./lisa/LisaRaw2Ana.cxx
#./bplast/bPlastReader.cxx
#./bplast/bPlastRaw2Cal.cxx
#./beammonitor/BeamMonitorReader.cxx
#./germanium/GermaniumRaw2Cal.cxx
#./germanium/GermaniumCal2Anl.cxx
#./fatima/FatimaReader.cxx
#./fatima/FatimaRaw2Cal.cxx
#./bgo/BGOReader.cxx
#./bgo/BGORaw2Cal.cxx
#./fatima/FatimaVmeReader.cxx
#./fatima/FatimaVmeRaw2Cal.cxx
#./bb7/BB7Reader.cxx
#./bb7/BB7FebexReader.cxx
#./bb7/BB7Raw2Cal.cxx
#./bb7/BB7FebexRaw2Cal.cxx
#./bb7/BB7FebexCal2Hit.cxx
#./fimp/FimpReader.cxx
#./fimp/FimpRaw2Cal.cxx

./test/TestReader.cxx
)

Set(STRUCT_HEADERS
./base/ext_h101_unpack.h
#./aida/ext_h101_aida.h
./frs/ext_h101_frs.h
#./travMus/ext_h101_travmus.h
#./lisa/ext_h101_lisa.h
#./germanium/ext_h101_germanium.h
#./bplast/ext_h101_bplast.h
#./beammonitor/ext_h101_beammonitor.h
#./fatima/ext_h101_fatima.h
#./fatima/ext_h101_fatimavme.h
#./bgo/ext_h101_bgo.h
# ./bb7/ext_h101_bb7vme.h
#./bb7/ext_h101_bbfebex.h
#./fimp/ext_h101_fimp.h

./test/ext_h101_test.h
)

# fill list of header files from list of source files
# by exchanging the file extension
CHANGE_FILE_EXTENSION(*.cxx *.h HEADERS "${SRCS}")
Set(HEADERS ${STRUCT_HEADERS} ${HEADERS})

set(LINKDEF SourceLinkDef.h)
set(DEPENDENCIES
    GeoBase ParBase MbsAPI Base FairTools
    sfsBase sfsData Core Geom GenVector
    Physics Matrix MathCore
    ${ucesb_LIBRARY_SHARED})
set(LIBRARY_NAME sfssource)

GENERATE_LIBRARY()
