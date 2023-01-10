#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define TEST  // Used to exclude error reporting and avoid having to link GCL + others.

#include "include/statistics/percentile.hpp"

BOOST_AUTO_TEST_SUITE(statistics_percentile)

BOOST_AUTO_TEST_CASE(valarray, *boost::unit_test::tolerance(0.001))
{
  std::valarray<int> X = { 97, 82, 52, 17, 7, 59, 10, 20, 37, 1, 57, 50, 56, 50, 99, 24, 4, 58, 98, 15, 78, 65, 63, 70, 96,
                              7, 54, 24, 10, 80, 45, 2, 62, 4, 13, 18, 17, 79 };
  std::valarray<int> A = { 97, 82, 52, 17, 7, 59, 10, 20, 37, 1, 57, 50, 56, 50, 99, 24, 4, 58, 98, 15, 78, 65, 63, 70, 96,
                              7, 54, 24, 10, 80, 45, 2, 62, 4, 13, 18, 17 };

  std::valarray<double> Y = { 46.9, 8.7, 8.2, 40.5, 95.4, 63.3, 10.3, 12.6, 30.5, 61.9, 61.2, 59.9, 65.2, 90.2, 98.0, 16.3, 4.4,
                              29.2, 71.2, 71.2, 76.1, 81.1, 15.9, 67.5, 19.6, 70.6, 37.4, 21.4, 88.3, 16.4, 37.0, 66.8, 36.3, 65.1,
                              42.6, 67.0, 44.3 };
  std::valarray<double> Z = { 46.9, 8.7, 8.2, 40.5, 95.4, 63.3, 10.3, 12.6, 30.5, 61.9, 61.2, 59.9, 65.2, 90.2, 98.0, 16.3, 4.4,
                              29.2, 71.2, 71.2, 76.10, 81.1, 15.9, 67.5, 19.6, 70.6, 37.4, 21.4, 88.3, 16.4, 37.0, 66.8, 36.3, 65.1,
                              42.6, 67.0 };

  std::valarray<std::uint16_t> B = { 6, 6, 7, 6, 6, 5, 4, 6, 7, 5, 3, 5, 4, 8, 6, 4, 4, 6, 4, 5, 4, 5, 26, 15, 9, 6, 57, 37, 5,
                                     9, 6, 8 };

  BOOST_TEST(MCL::percentile(X, 0.1) == 4);
  BOOST_TEST(MCL::percentile(X, 0.2) == 10);
  BOOST_TEST(MCL::percentile(X, 0.5) == 50);
  BOOST_TEST(MCL::percentile(X, 0.9) == 96.1);

  BOOST_TEST(MCL::percentile(A, 0.8) == 73.2);
  BOOST_TEST(MCL::percentile(A, 0.9) == 96.2);

  BOOST_TEST(MCL::percentile(Y, 0.5) == 46.9);
  BOOST_TEST(MCL::percentile(Y, 0.75) == 69.1);
  BOOST_TEST(MCL::percentile(Y, 0.95) == 95.7);

  BOOST_TEST(MCL::percentile(Z, 0.75) == 69.851);
  BOOST_TEST(MCL::percentile(Z, 0.85) == 78.3);

  BOOST_TEST(MCL::percentile(B, 0.90) == 22.7);
}

BOOST_AUTO_TEST_SUITE_END()
