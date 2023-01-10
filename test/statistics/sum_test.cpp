#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define TEST  // Used to exclude error reporting and avoid having to link GCL + others.


#include "include/statistics/sum.hpp"

BOOST_AUTO_TEST_SUITE(statistics_sum)

BOOST_AUTO_TEST_CASE(valarray, *boost::unit_test::tolerance(0.001))
{
  std::valarray<double> X = {1.47, 1.50, 1.52, 1.55, 1.57, 1.60, 1.63, 1.65, 1.68, 1.70, 1.73, 1.75, 1.78, 1.80, 1.83};
  std::valarray<int> Y = {68, 60, 29, 98, 39, 6, 71, 52, 49, 83, 4, 37, 70, 81, 54, 78, 11, 50, 72, 14, 89, 67, 16, 64, 18,
                          51, 87, 32, 17, 32, 80, 52, 21, 87, 7, 15, 85, 20 };
  std::valarray<double> Z(0);

  BOOST_TEST(MCL::sum(X) == 24.76);
  BOOST_TEST(MCL::sum(Y) == 1866);
  BOOST_TEST(MCL::sum(Z) == 0);

}

BOOST_AUTO_TEST_SUITE_END()
