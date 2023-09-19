//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								futureValue.hpp
// SUBSYSTEM:						Financial Functions.
// LANGUAGE:						C++
// TARGET OS:						None.
// LIBRARY DEPENDANCE:	none
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2020-2022 Gavin Blakeman.
//                      This file is part of the Maths Class Library (MCL)
//
//                      MCL is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
//                      License as published by the Free Software Foundation, either version 2 of the License, or (at your option)
//                      any later version.
//
//                      MCL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//                      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
//                      more details.
//
//                      You should have received a copy of the GNU General Public License along with MCL.  If not, see
//                      <http://www.gnu.org/licenses/>.
//
// OVERVIEW:            Implementation of templated and multi-threaded financial functions.
//
// CLASSES INCLUDED:    None
//
// FUNCTIONS INCLUDED:
//
//
// HISTORY:             2020-04-18 GGB - File Created
//
//*********************************************************************************************************************************

#ifndef MCL_FUTUREVALUE_HPP
#define MCL_FUTUREVALUE_HPP

  // Standard C++ library header files

#include <cstdint>
#include <vector>

namespace MCL
{
  /// @brief Calculate the future value based on a number of periods and a constant discount rate.
  /// @param[in] pv: The present value
  /// @param[in] rate: The discount rate
  /// @param[in] np: The number of periods.
  /// @returns The future value.
  /// @throws
  /// @version 2020-04-18/GGB - Function created.

  template<typename T>
  T FV(T const &pv, double rate, std::uint32_t np)
  {
    return T(pv * (1 + rate) ^ np);
  }

  /// @brief Calculate the future value based on a number of periods and a varying discount rate.
  /// @param[in] pv: The present value
  /// @param[in[ rates: std::vector containing the discount rates per period.
  /// @returns The future value.
  /// @throws
  /// @version 2020-04-18/GGB - Function created.
  /// @todo 1. Add multi-threading for large vectors.

  template<typename T, typename R>
  T FV(T pv, std::vector<R> rates)
  {
    for (R const & dr : rates)
    {
      pv *= (1 + dr);
    };

    return pv;
  }

} // namespace MCL

#endif // MCL_FUTUREVALUE_HPP
