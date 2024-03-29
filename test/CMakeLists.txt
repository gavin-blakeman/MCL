﻿# Tests for MCL

CMAKE_MINIMUM_REQUIRED(VERSION 3.16 FATAL_ERROR)

PROJECT(MCL_tests)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_MULTITHREADED ON)

find_package(Boost CONFIG)
find_package(Boost REQUIRED COMPONENTS locale thread unit_test_framework)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}../../)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

set(SOURCES
  main.cpp
  financial/test_xirr.cpp
  functions/linearRegression.cpp
  statistics/mean_test.cpp
  statistics/median_test.cpp
  statistics/percentile_test.cpp
  statistics/stdev_test.cpp
  statistics/sum_test.cpp
  statistics/distributionFunctions/weibull_test.cpp
  statistics/anderson-darling_test.cpp)

set(LIBRARIES
  GCL
  MCL
  mpfr
  ${Boost_LIBRARIES}
  )
  
  
set(DIRECTORIES
  ${CMAKE_SOURCE_DIR}/GCL
  ${CMAKE_SOURCE_DIR}/SCL
  )

LINK_DIRECTORIES(${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LIBRARIES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} PRIVATE ${DIRECTORIES})


ENABLE_TESTING()
ADD_TEST(${PROJECT_NAME} ${PROJECT_NAME})

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} COMMENT "Run tests" POST_BUILD  COMMAND ${PROJECT_NAME})

