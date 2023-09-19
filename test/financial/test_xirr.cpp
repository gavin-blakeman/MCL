#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define TEST  // Used to exclude error reporting and avoid having to link GCL + others.

#include <vector>

#include "include/financial/xirr.h"

BOOST_AUTO_TEST_SUITE(financial_xirr)

BOOST_AUTO_TEST_CASE(Case1, *boost::unit_test::tolerance(0.001))
{
  using namespace MCL;

  cashflowVector_t cashflows =
  {
    {std::chrono::January/1/2017, -500},
    {std::chrono::February/1/2017, -500},
    {std::chrono::March/1/2017, -500},
    {std::chrono::April/1/2017, -500},
    {std::chrono::May/1/2017, -500},
    {std::chrono::June/1/2017, -500},
    {std::chrono::July/1/2017, -500},
    {std::chrono::August/1/2017, -500},
    {std::chrono::September/1/2017, -500},
    {std::chrono::October/1/2017, -500},
    {std::chrono::November/1/2017, -500},
    {std::chrono::December/1/2017, -500},
  };

  BOOST_REQUIRE_THROW(XIRR(cashflows), std::runtime_error);
  cashflows.emplace_back(std::chrono::January/1/2018, 6545.08);

  BOOST_REQUIRE_NO_THROW(XIRR(cashflows));
  BOOST_TEST(XIRR(cashflows) == 0.171156);

}

BOOST_AUTO_TEST_CASE(Case2, *boost::unit_test::tolerance(0.001))
{
  using namespace MCL;

  cashflowVector_t cashflows =
  {
    {std::chrono::January/1/2008, -10000},
    {std::chrono::March/1/2008, 2750},
    {std::chrono::October/30/2008, 4250},
    {std::chrono::February/15/2009, 3250},
    {std::chrono::April/1/2009, 2750},
  };

  BOOST_TEST(XIRR(cashflows) == 0.3733625);

}

BOOST_AUTO_TEST_SUITE_END()
