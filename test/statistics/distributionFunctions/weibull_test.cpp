#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define TEST  // Used to exclude error reporting and avoid having to link GCL + others.

#include "include/statistics/distributionFunctions/weibull.hpp"

BOOST_AUTO_TEST_SUITE(statistics_distributionFunctions_weibull)

BOOST_AUTO_TEST_CASE(regression_dataSet1, *boost::unit_test::tolerance(0.001))
{
  std::valarray<double> N = {509, 660, 386, 753, 811, 613, 848, 725, 315, 872, 487, 512};


  std::pair<double, double> rv = MCL::weibull_regression(N);

  BOOST_TEST(rv.first == 692.088);
  BOOST_TEST(rv.second == 3.745);

}


BOOST_AUTO_TEST_SUITE_END()
