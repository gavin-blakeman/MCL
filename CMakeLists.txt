# MCL Library CMAKE file

CMAKE_MINIMUM_REQUIRED(VERSION 3.14 FATAL_ERROR)

PROJECT(MCL)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(NOT DEFINED $CMAKE_BINARY_DIR)
  IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    SET(BUILD_FOR_WIN TRUE)
  ELSE()
  ENDIF()
ENDIF(NOT DEFINED $CMAKE_BINARY_DIR)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(SOURCES
  source/financial/xirr.cpp
  source/angle.cpp
  source/common.cpp
  source/numeric.cpp
  source/Shared.cpp
  )
set(HEADERS
  include/financial/futureValue.hpp
  include/financial/xirr.h
  include/statistics/mean.hpp
  include/statistics/median.hpp
  include/statistics/minmax.hpp
  include/statistics/percentile.hpp
  include/statistics/stdev.hpp
  include/statistics/sum.hpp
  include/statistics/variance.hpp
  include/common.h
  include/config.h
  include/constants.h
  MCL
  )
  
  set(DIRECTORIES  
  ${CMAKE_SOURCE_DIR}/GCL
  ${CMAKE_SOURCE_DIR}/SCL    
  ../fmt/include
  ${Boost_INCLUDE_DIRS}
  )

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE ${DIRECTORIES})

#ADD_SUBDIRECTORY(test)










