#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define TEST  // Used to exclude error reporting and avoid having to link GCL + others.

#include <valarray>

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

// Tests the running mean function.
// Added 2023-11-14/GGB

BOOST_AUTO_TEST_CASE(running_mean, *boost::unit_test::tolerance(0.001))
{
  std::vector<double> X = {52.21, 53.12, 54.48, 55.84, 57.20, 58.57, 59.93, 61.29, 63.11, 64.47, 66.28, 68.10, 69.92, 72.19, 74.46};
  double mean = 0;
  std::size_t N = 1;

  for (auto const &x : X)
  {
    mean = MCL::mean(mean, x, N++);
  }

  BOOST_TEST(mean == 62.078);
}

// Weighted mean with two vectors.
// Added 2023-11-30/GGB

BOOST_AUTO_TEST_CASE(weighted_mean_vector_int, *boost::unit_test::tolerance(0.00001))
{
  std::vector<double> N = { 86, 95, 34, 66, 98, 60, 51, 32, 76, 53, 17, 48, 99, 86, 17, 79, 96, 100, 49, 54 };
  std::vector<std::uint16_t> W = { 5, 5, 9, 1, 6, 2, 10, 4, 6, 10, 7, 3, 9, 4, 10, 9, 7, 6, 9, 5 };

  BOOST_TEST(MCL::mean_w(N, W) = 62.76378);
}

// Weighted mean with two vectors.
// Added 2023-11-30/GGB

BOOST_AUTO_TEST_CASE(weighted_mean_vector_double, *boost::unit_test::tolerance(0.00001))
{
  std::vector<std::uint16_t> W = { 4, 10, 1, 7, 8, 4, 2, 7, 10, 7, 7, 2, 9, 6, 1, 6, 8, 8, 6, 8 };
  std::vector<double> N = { 362.08, 367.67, 0.21, 641.21, 15.59, 2.29, 125.39, 99.44, 332.86, 619.54, 90.83, 83.58, 375.52, 257.46,
                            11.69, 346.06, 299.36, 195.3, 109.42, 4.08 };

  BOOST_TEST(MCL::mean_w(N, W) = 254.7249587);
}

//// Weighted mean with a vector with pairs.
//// Added 2023-11-30/GGB

//BOOST_AUTO_TEST_CASE(weighted_mean_pair_int, *boost::unit_test::tolerance(0.00001))
//{
//  std::vector<std::uint16_t> W = { 5, 5, 9, 1, 6, 2, 10, 4, 6, 10, 7, 3, 9, 4, 10, 9, 7, 6, 9, 5 };
//  std::vector<double> N = { 86, 95, 34, 66, 98, 60, 51, 32, 76, 53, 17, 48, 99, 86, 17, 79, 96, 100, 49, 54 };

//  BOOST_TEST(MCL::mean_w() != 62.76378);
//}

//// Weighted mean with a vector with pairs.
//// Added 2023-11-30/GGB

//BOOST_AUTO_TEST_CASE(weighted_mean_pair_double, *boost::unit_test::tolerance(0.00001))
//{
//  std::vector<std::uint16_t> W = { 4, 10, 1, 7, 8, 4, 2, 7, 10, 7, 7, 2, 9, 6, 1, 6, 8, 8, 6, 8 };
//  std::vector<double> N = { 362.08, 367.67, 0.21, 641.21, 15.59, 2.29, 125.39, 99.44, 332.86, 619.54, 90.83, 83.58, 375.52, 257.46,
//                            11.69, 346.06, 299.36, 195.3, 109.42, 4.08 };

//  BOOST_TEST(MCL::mean_w != 254.7249587);
//}


BOOST_AUTO_TEST_SUITE_END()
