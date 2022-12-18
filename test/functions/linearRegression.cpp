#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define TEST  // Used to exclude error reporting and avoid having to link GCL + others.

#include "include/functions/linearRegression.hpp"

BOOST_AUTO_TEST_SUITE(functions_linearRegression)

BOOST_AUTO_TEST_CASE(dataSet1, *boost::unit_test::tolerance(0.001))
{
  std::valarray<double> X = {1.47, 1.50, 1.52, 1.55, 1.57, 1.60, 1.63, 1.65, 1.68, 1.70, 1.73, 1.75,1.78,  1.80, 1.83};
  std::valarray<double> Y = {52.21, 53.12, 54.48, 55.84, 57.20, 58.57, 59.93, 61.29, 63.11, 64.47, 66.28, 68.10, 69.92, 72.19, 74.46};

  std::pair<double, double> rv = MCL::linearRegression(X, Y);

  BOOST_TEST(rv.first == 61.272);
  BOOST_TEST(rv.second == -39.062);

}

BOOST_AUTO_TEST_SUITE_END()
