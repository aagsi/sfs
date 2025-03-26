Set(SYSTEM_INCLUDE_DIRECTORIES
${SYSTEM_INCLUDE_DIRECTORIES}
${BASE_INCLUDE_DIRECTORIES}
)

set(INCLUDE_DIRECTORIES
#put here all directories where header files are located
${SFSROOT_SOURCE_DIR}/sfsbase
${SFSROOT_SOURCE_DIR}/sfsdata
${SFSROOT_SOURCE_DIR}/sfsdata/frsData
${SFSROOT_SOURCE_DIR}/sfsdata/germaniumData
${SFSROOT_SOURCE_DIR}/sfsdata/aidaData
${SFSROOT_SOURCE_DIR}/sfsdata/bplastData
${SFSROOT_SOURCE_DIR}/sfsdata/fatimaData
${SFSROOT_SOURCE_DIR}/sfsdata/bgoData
${SFSROOT_SOURCE_DIR}/sfsdata/lisaData
${SFSROOT_SOURCE_DIR}/sfsdata/wrData
${SFSROOT_SOURCE_DIR}/sfsdata/beammonitorData
${SFSROOT_SOURCE_DIR}/sfsdata/timemachineData
${SFSROOT_SOURCE_DIR}/sfsdata/baseData
${SFSROOT_SOURCE_DIR}/sfsdata/bb7Data
${SFSROOT_SOURCE_DIR}/sfsdata/fimpData
${SFSROOT_SOURCE_DIR}/sfsdata/travMusData
${SFSROOT_SOURCE_DIR}/analysis
${SFSROOT_SOURCE_DIR}/analysis/frs
${SFSROOT_SOURCE_DIR}/analysis/pars
${SFSROOT_SOURCE_DIR}/analysis/offline
${SFSROOT_SOURCE_DIR}/analysis/nearline
${SFSROOT_SOURCE_DIR}/analysis/nearline/bplast
${SFSROOT_SOURCE_DIR}/analysis/online
${SFSROOT_SOURCE_DIR}/analysis/online/frs
${SFSROOT_SOURCE_DIR}/correlations
${SFSROOT_SOURCE_DIR}/sfssource
${SFSROOT_SOURCE_DIR}/sfssource/frs
${SFSROOT_SOURCE_DIR}/sfssource/base
${SFSROOT_SOURCE_DIR}/sfssource/bplast
${SFSROOT_SOURCE_DIR}/sfssource/bb7
${SFSROOT_SOURCE_DIR}/sfssource/fimp
)

include_directories( ${INCLUDE_DIRECTORIES})
include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})

link_directories(${FAIRROOT_LIBRARY_DIR} ${ROOT_LIBRARY_DIR})

set(SRCS
#online
./online/germanium/GermaniumOnlineSpectra.cxx
./nearline/germanium/GermaniumResolution.cxx
./online/beammonitor/BeamMonitorOnlineSpectra.cxx
./online/lisa/LisaOnlineSpectra.cxx
./online/lisa/LisaOnlineSpectraDaq.cxx
./online/aida/AidaOnlineSpectra.cxx
./online/aida/AidaPulserWalkthrough.cxx
./online/bplast/bPlastOnlineSpectra.cxx
./online/fatima/FatimaOnlineSpectra.cxx
./online/fatima/FatimaVmeOnlineSpectra.cxx
./online/frs/FrsOnlineSpectra.cxx
./online/frs/FrsRawSpectra.cxx
./online/frs/FrsCalSpectra.cxx
./online/travMus/TravMusOnlineSpectra.cxx
./online/bgo/BGOOnlineSpectra.cxx
./online/timemachine/TimeMachineOnline.cxx
./online/wr/WhiterabbitCorrelationOnline.cxx
./online/bb7/BB7OnlineSpectra.cxx
./online/bb7/BB7FebexOnlineSpectra.cxx
./online/fimp/FimpOnlineSpectra.cxx

# nearline/offline
./nearline/bplast/bPlastNearlineSpectra.cxx
./nearline/fatima/FatimaNearlineSpectra.cxx
./nearline/fatima/FatimaVmeNearlineSpectra.cxx
./nearline/aida/AidaNearlineSpectra.cxx
./nearline/frs/FrsNearlineSpectra.cxx
./nearline/frs/FrsRawNearlineSpectra.cxx
./nearline/travMus/TravMusNearlineSpectra.cxx
./nearline/germanium/GermaniumNearlineSpectra.cxx
./nearline/bgo/BGONearlineSpectra.cxx
./nearline/wr/WhiterabbitCorrelationNearline.cxx
./nearline/timemachine/TimeMachineNearline.cxx
./nearline/lisa/LisaNearlineSpectra.cxx
./nearline/lisa/LisaNearlineSpectraDaq.cxx
./nearline/lisa/LisaTraceAnalysis.cxx
./nearline/fimp/FimpNearlineSpectra.cxx
./nearline/bb7/BB7NearlineSpectra.cxx
./nearline/lisa/LisaNearlineSpectra.cxx

## correlations ##
./correlations/FrsAidaCorrelations.cxx
./online/onlineCorrelations/FrsAidaCorrelationsOnline.cxx
./correlations/FrsFatimaCorrelations.cxx
#./correlations/FrsFatimaVmeCorrelations.cxx
./correlations/FrsGermaniumCorrelations.cxx
./correlations/FrsFatimaCorrelationsNearline.cxx
./correlations/FrsGermaniumCorrelationsNearline.cxx
./correlations/AidaFatimaCorrelations.cxx
./nearline/fatima/FatimaTimingAnalysis.cxx
./nearline/fatima/FatimaSinglesAnalysis.cxx
./correlations/AidaGermaniumCorrelations.cxx
./correlations/bPlastGermaniumCorrelations.cxx
./online/onlineCorrelations/bPlastGermaniumCorrelationsOnline.cxx
./online/onlineCorrelations/BB7GermaniumCorrelationsOnline.cxx
#./correlations/FrsBplastCorrelations.cxx
./correlations/triplePlusCorrs/BetaIonCorrelations.cxx


#./frs/MHTDCSpectra.cxx
#./frs/TPCCorrections.cxx
#./correlations/FrsBplastCorrelations.cxx
./online/onlineCorrelations/LisaFrsCorrelationsOnline.cxx
./correlations/LisaFrsCorrelations.cxx
./correlations/FrsTravMusCorrelations.cxx

)


#file(GLOB SRCS ./online/*.cxx ./offline/*.cxx ./pars/*.cxx)

# fill list of header files from list of source files
# by exchanging the file extension
CHANGE_FILE_EXTENSION(*.cxx *.h HEADERS "${SRCS}")

Set(LINKDEF AnaLinkDef.h)

Set(DEPENDENCIES
GeoBase ParBase MbsAPI Base FairTools sfsBase sfsData Core Geom GenVector Physics Matrix MathCore

)

Set(LIBRARY_NAME sfsAnalysis)

GENERATE_LIBRARY()
