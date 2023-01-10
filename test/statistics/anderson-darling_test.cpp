#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define TEST  // Used to exclude error reporting and avoid having to link GCL + others.

#include <vector>

#include "include/statistics/anderson-darling.hpp"
#include "include/statistics/mean.hpp"
#include "include/statistics/stdev.hpp"

BOOST_AUTO_TEST_SUITE(statistics_anderson_darling)

BOOST_AUTO_TEST_CASE(valarray, *boost::unit_test::tolerance(0.001))
{
  std::valarray<double> X = {1.2, 2.6, 1.6, 7.6, 6.6, 1.7, 2.0, 1.9, 4.8, 3.0, 3.5, 4.0, 1.8, 5.6, 2.2 };
  std::valarray<double> Y = {52.21, 53.12, 54.48, 55.84, 57.20, 58.57, 59.93, 61.29, 63.11, 64.47, 66.28, 68.10, 69.92, 72.19, 74.46};
  std::valarray<float> Z =  {0.54, 1.21, 2.74, -0.19, 1.55, -0.17, 1.34, 0.52, -0.02, 2.53, 1.82, 1.22, 2.17, 0.50, -0.70, 0.19};

  std::vector<MCL::goodnessOfFit_t> GOF = { {.PDF = MCL::PDF_NORMAL, .parameters{ 1, 1}, .alpha = 0.05 }};
//  MCL::anderson_darling_1S(Z, GOF);
//  BOOST_TEST(GOF[0].H0 == true);

  GOF.clear();
  GOF = {{.PDF = MCL::PDF_NORMAL, .parameters{MCL::mean(X), MCL::stdev(X)}, .alpha = 0.05 }};

  MCL::anderson_darling_1S(X, GOF);
  BOOST_TEST(GOF[0].H0 == false);   // Data is not normal.

//  GOF.clear();
//  GOF = { {.PDF = MCL::PDF_NORMAL, .parameters{MCL::mean(Y), MCL::stdev(Y)}, .alpha = 0.05 }};
//  MCL::anderson_darling_1S(Y, GOF);
//  BOOST_TEST(GOF[0].H0 == true);

//  BOOST_TEST(MCL::mean(Y) == 62.078);

}

BOOST_AUTO_TEST_SUITE_END()
