//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								gcd.hpp
// SUBSYSTEM:						Maths Functions
// LANGUAGE:						C++
// TARGET OS:						None.
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2020 Gavin Blakeman.
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
// OVERVIEW:            Implementation of a greatest common divisor function
//
// CLASSES INCLUDED:    None
//
//
// HISTORY:             2020-04-24 GGB - File Created
//
//*********************************************************************************************************************************

#ifndef GCD_HPP
#define GCD_HPP

  // Standard C++ library header files.

#include <stdexcept>
#include <type_traits>

namespace MCL
{
  /// @brief Calculate the GCD using Euclid's algorithm.
  /// @param[in] a: The first value
  /// @param[in] b: Second value


  template<typename T>
  T gcd(T a, T b)
  {
    static_assert(std::is_integral<T>::value, "Unsigned Integer type required.");
    static_assert(std::is_signed<T>::value, "Signed integer type required.");

    if ( (a == 0) || (b == 0))
    {
      throw std::runtime_error("MCL::gcd - Parameters cannot be zero.");
    }
    else
    {
      if (a < 0)
      {
        a = -a;
      };
      if (b < 0)
      {
        b = -b;
      };

      while (a != b)
      {
        if (a > b)
        {
          a -= b;
        }
        else
        {
          b -= a;
        }
      };

      return a;
    };
  }

} // namespace MCL

#endif // GCD_HPP
