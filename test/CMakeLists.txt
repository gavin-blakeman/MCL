# Tests for MCL

CMAKE_MINIMUM_REQUIRED(VERSION 3.16 FATAL_ERROR)

PROJECT(MCL_TESTS)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

find_package(Boost COMPONENTS thread unit_test_framework REQUIRED)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}../)
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

LINK_DIRECTORIES(${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${Boost_LIBRARIES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} MCL)

target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE "../GCL")


ENABLE_TESTING()
ADD_TEST(${PROJECT_NAME} ${PROJECT_NAME})

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} COMMENT "Run tests" POST_BUILD  COMMAND ${PROJECT_NAME})

