set(SYSTEM_INCLUDE_DIRECTORIES ${SYSTEM_INCLUDE_DIRECTORIES} ${BASE_INCLUDE_DIRECTORIES})

set(INCLUDE_DIRECTORIES
${SFSROOT_SOURCE_DIR}/sfsbase
${SFSROOT_SOURCE_DIR}/sfsdata
${SFSROOT_SOURCE_DIR}/sfsdata/frsData
#${SFSROOT_SOURCE_DIR}/sfsdata/lisaData
#${SFSROOT_SOURCE_DIR}/sfsdata/aidaData
#${SFSROOT_SOURCE_DIR}/sfsdata/fatimaData
#${SFSROOT_SOURCE_DIR}/sfsdata/bplastData
#${SFSROOT_SOURCE_DIR}/sfsdata/bgoData
#${SFSROOT_SOURCE_DIR}/sfsdata/germaniumData
#${SFSROOT_SOURCE_DIR}/sfsdata/beammonitorData
#${SFSROOT_SOURCE_DIR}/sfsdata/timemachineData
${SFSROOT_SOURCE_DIR}/sfsdata/baseData
#${SFSROOT_SOURCE_DIR}/sfsdata/bb7Data
#${SFSROOT_SOURCE_DIR}/sfsdata/fimpData
#${SFSROOT_SOURCE_DIR}/sfsdata/travMusData
${SFSROOT_SOURCE_DIR}/sfssource
${SFSROOT_SOURCE_DIR}/sfssource/frs
)

include_directories(${INCLUDE_DIRECTORIES})
include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES ${ROOT_LIBRARY_DIR} ${FAIRROOT_LIBRARY_DIR})

link_directories(${LINK_DIRECTORIES})

set(SRCS
frsData/FrsData.cxx
frsData/FrsCalData.cxx
frsData/FrsHitData.cxx
#travMusData/TravMusData.cxx
#travMusData/TravMusCalData.cxx
#travMusData/TravMusAnaData.cxx
#lisaData/LisaData.cxx
#lisaData/LisaCalData.cxx
#lisaData/LisaAnaData.cxx
#lisaData/LisaTraceData.cxx
#aidaData/AidaData.cxx
#aidaData/AidaCalData.cxx
#aidaData/AidaHitData.cxx
#aidaData/TAidaConfiguration.cxx
#germaniumData/GermaniumFebexData.cxx
#germaniumData/GermaniumCalData.cxx
#germaniumData/TGermaniumConfiguration.cxx
#bplastData/bPlastTwinpeaksData.cxx
#bplastData/bPlastTwinpeaksCalData.cxx
#bplastData/TbPlastConfiguration.cxx
#beammonitorData/BeamMonitorData.cxx
#fatimaData/FatimaTwinpeaksData.cxx
#fatimaData/FatimaTwinpeaksCalData.cxx
#fatimaData/TFatimaTwinpeaksConfiguration.cxx
#bgoData/BGOTwinpeaksData.cxx
#bgoData/BGOTwinpeaksCalData.cxx
#bgoData/TBGOTwinpeaksConfiguration.cxx
#fatimaData/TFatimaVmeConfiguration.cxx
#fatimaData/FatimaVmeData.cxx
#fatimaData/FatimaVmeCalData.cxx
#timemachineData/TimeMachineData.cxx
#bb7Data/BB7VmeData.cxx
#bb7Data/BB7VmeCalData.cxx
#bb7Data/BB7FebexData.cxx
#bb7Data/BB7FebexCalData.cxx
#bb7Data/BB7FebexHitData.cxx
#bb7Data/TBB7VmeConfiguration.cxx
#bb7Data/TBB7FebexConfiguration.cxx
#fimpData/FimpData.cxx
#fimpData/FimpCalData.cxx
#fimpData/TFimpConfiguration.cxx
frsData/TFRSParameter.cxx
frsData/TFrsConfiguration.cxx
frsData/FrsGate.cxx
baseData/TCorrelationsConfiguration.cxx
baseData/TExperimentConfiguration.cxx
#lisaData/TLisaConfiguration.cxx
)

# fill list of header files from list of source files by exchanging the file extension
change_file_extension(*.cxx *.h HEADERS "${SRCS}")

set(LINKDEF DataLinkDef.h)
set(LIBRARY_NAME sfsData)
set(DEPENDENCIES Base FairTools ${VMCLIB} FairLogger::FairLogger)

generate_library()
