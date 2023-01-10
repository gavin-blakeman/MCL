# Tests for MCL

CMAKE_MINIMUM_REQUIRED(VERSION 3.14 FATAL_ERROR)

PROJECT(MCL_TESTS)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/MCL)

FIND_PACKAGE(Boost 1.79 REQUIRED COMPONENTS unit_test_framework locale REQUIRED)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}../)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
#MESSAGE( ${Boost_INCLUDE_DIRS})

LINK_DIRECTORIES(${CMAKE_BINARY_DIR})

ADD_EXECUTABLE(MCL_testSuite ${PROJECT_SOURCE_DIR}/main.cpp
                             ${PROJECT_SOURCE_DIR}/functions/linearRegression.cpp
                             ${PROJECT_SOURCE_DIR}/statistics/mean_test.cpp
                             ${PROJECT_SOURCE_DIR}/statistics/median_test.cpp
                             ${PROJECT_SOURCE_DIR}/statistics/percentile_test.cpp
                             ${PROJECT_SOURCE_DIR}/statistics/stdev_test.cpp
                             ${PROJECT_SOURCE_DIR}/statistics/sum_test.cpp
                             ${PROJECT_SOURCE_DIR}/statistics/distributionFunctions/weibull_test.cpp
                             ${PROJECT_SOURCE_DIR}/statistics/anderson-darling_test.cpp
              )
TARGET_LINK_LIBRARIES(MCL_testSuite ${Boost_LIBRARIES})
TARGET_LINK_LIBRARIES(MCL_testSuite MCL)

ENABLE_TESTING()
ADD_TEST(MCL_testSuite MCL_testSuite)

ADD_CUSTOM_COMMAND(TARGET MCL_testSuite COMMENT "Run tests" POST_BUILD  COMMAND MCL_testSuite)
