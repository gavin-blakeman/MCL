# MCL Library CMAKE file

CMAKE_MINIMUM_REQUIRED(VERSION 3.14 FATAL_ERROR)

PROJECT(MCL)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(NOT DEFINED $CMAKE_BINARY_DIR)
  IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    SET(BUILD_FOR_WIN TRUE)
    SET(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/win64)
  ELSE()
    SET(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/linux)
  ENDIF()
ENDIF(NOT DEFINED $CMAKE_BINARY_DIR)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(SOURCES
  source/financial/xirr.cpp
  source/angle.cpp
  source/common.cpp
  source/numeric.cpp
  source/Shared.cpp)
set(HEADERS
  include/financial/xirr.h
  include/statistics/mean.hpp
  include/statistics/median.hpp
  include/statistics/minmax.hpp
  include/statistics/percentile.hpp
  include/statistics/sum.hpp
  include/statistics/variance.hpp
  include/common.h
  include/config.h
  include/constants.h)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE "../GCL")

#ADD_SUBDIRECTORY(test)










