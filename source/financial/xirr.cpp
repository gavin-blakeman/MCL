#include "include/financial/xirr.h"

#include <cmath>
#include <iostream>

namespace MCL
{

  static double solver(cashflowVector_t const &cashflows, std::vector<double> const &diffDates, double rate)
  {
    double rv = 0;
    std::size_t i;

    rate += 1;

    for (i = 0; i < cashflows.size(); i++)
    {
      rv += cashflows[i].second * std::pow(rate, diffDates[i]);
    }

    return rv;
  }

  /// @brief      Calculate the internal rate of return for a sequence of cash flows.
  /// @param[in]  cashflows: A sequence of cashflows (Dates and values)
  /// @param[in]  prec: The required precision.
  /// @version    2023-07-17/GGB - Function created.

  double XIRR(cashflowVector_t const &cashflows, double prec)
  {
    bool allPositive = true, allNegative = true, allZero = true;
    std::vector<double> diffDates;

    if (cashflows.size() == 0)
    {
      throw std::runtime_error("MCL::XIRR() - No data provided.");
    }

    for (auto const &cf: cashflows)
    {
      diffDates.push_back((double) std::chrono::duration_cast<std::chrono::days>(cashflows.back().first - cf.first).count() / 365);

      if (cf.second > 0)
      {
        allNegative = false;
        allZero = false;
      }
      else if (cf.second < 0)
      {
        allPositive = false;
        allZero = false;
      }
    }

    if (allPositive)
    {
      throw std::runtime_error("MCL::XIRR() - All cashflows positive.");
    }
    if (allNegative)
    {
      throw std::runtime_error("MCL::XIRR() - All cashflows negative.");
    }
    if (allZero)
    {
      throw std::runtime_error("MCL::XIRR() - All cashflows zero.");
    };

    double rMin = -(1 - prec);
    double rMax = 10;
    double rMid;
    double fMin = solver(cashflows, diffDates, rMin);
    double fMax = solver(cashflows, diffDates, rMax);
    double fMid;

    if (std::abs(fMax) > std::abs(fMin))
    {
      fMid = fMin;
      rMid = rMin;
    }
    else
    {
      fMid = fMax;
      rMid = rMax;
    }

    while (std::abs(fMid) > prec)
    {
      if (std::signbit(fMin) == std::signbit(fMax))
      {
        throw std::runtime_error("MCL::XIRR() - Unable to converge.");
      }
      else
      {
        rMid = (rMax + rMin) / 2;
        fMid = solver(cashflows, diffDates, rMid);

        if (std::abs(fMid) > prec)
        {
          if (std::signbit(fMin) == std::signbit(fMid))
          {
            rMin = rMid;
            fMin = fMid;
          }
          else
          {
            rMax = rMid;
            fMax = fMid;
          }
        };
      }
    }

    return rMid;

  }
}
