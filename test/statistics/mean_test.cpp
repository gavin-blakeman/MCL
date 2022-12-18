#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define TEST  // Used to exclude error reporting and avoid having to link GCL + others.

#include <vector>

#include "include/statistics/mean.hpp"

BOOST_AUTO_TEST_SUITE(statistics_mean)

BOOST_AUTO_TEST_CASE(valarray, *boost::unit_test::tolerance(0.001))
{
  std::valarray<double> X = {1.47, 1.50, 1.52, 1.55, 1.57, 1.60, 1.63, 1.65, 1.68, 1.70, 1.73, 1.75,1.78,  1.80, 1.83};
  std::valarray<double> Y = {52.21, 53.12, 54.48, 55.84, 57.20, 58.57, 59.93, 61.29, 63.11, 64.47, 66.28, 68.10, 69.92, 72.19, 74.46};

  BOOST_TEST(MCL::mean(X) == 1.650);
  BOOST_TEST(MCL::mean(Y) == 62.078);

}

BOOST_AUTO_TEST_CASE(c_array, *boost::unit_test::tolerance(0.001))
{
  std::vector<double> X = {1.47, 1.50, 1.52, 1.55, 1.57, 1.60, 1.63, 1.65, 1.68, 1.70, 1.73, 1.75,1.78,  1.80, 1.83};
  std::vector<double> Y = {52.21, 53.12, 54.48, 55.84, 57.20, 58.57, 59.93, 61.29, 63.11, 64.47, 66.28, 68.10, 69.92, 72.19, 74.46};

  BOOST_TEST(*MCL::mean(X.data(), X.size()) == 1.650);
  BOOST_TEST(*MCL::mean(Y.data(), Y.size()) == 62.078);
}

BOOST_AUTO_TEST_SUITE_END()
