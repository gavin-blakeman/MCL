//*************************************************************************************************
//
// PROJECT:							MCL (Math Class Library)
// FILE:								Functions.hpp
// SUBSYSTEM:						Numeric classes.
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2014-2018 Gavin Blakeman.
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
// OVERVIEW:            Provides some overloaded mathematical functions.
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2014-01-13 GGB - File Created.
//
//*************************************************************************************************

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

  // Standard C++ library header files.

#include <cmath>

  // MCL library header files

#include "constants.h"

namespace MCL
{
  /// @brief Function to convert degrees to radians.
  /// @param[in] x: The value to convert.
  /// @returns The value in degrees.
  /// @throws None.
  /// @version 2018-08-23/GGB - Function created.

  template<typename T>
  inline T D2R(T const &x)
  {
    return x * D_D2R;
  }

  /// @brief Function to convert radians to degrees.
  /// @param[in] x: The value to convert.
  /// @returns The value in degrees.
  /// @throws None.
  /// @version 2018-08-23/GGB - Function created.

  template<typename T>
  inline T R2D(T const &x)
  {
    return x * D_R2D;
  }


  /// @brief Raise a number to power 2.
  /// @param[in] x: Value to square.
  /// @returns The value x^2.
  /// @throws None.
  /// @version 2014-12-31/GGB - Function created.

  template<typename T>
  inline T pow2(T x)
  {
    return x * x;
  }

  /// Calculates x^3 (cube)
  //
  // 2014-01-26/GGB - Function created.

  template<typename T>
  inline T pow3(T x)
  {
    return x * x * x;
  }

  /// @brief Calculates the Modulo with range[0; range]
  /// @param[in] val: The value to modulo.
  /// @param[in] range: The range to work with.
  /// @returns The value within the range [0; range]
  /// @version 2013-01-13/GGB - Function created.

  template<typename T, typename U>
  inline T moduloN(T val, U range)
  {
    return (val - range * std::floor(val/range));
  }

  /// @brief Calulates the modulo with a range of [-range; range]
  /// @param[in] val: The value to modulo.
  /// @param[in] range: The range to work within.
  /// @returns The value within the +- range limits given
  /// @version 2018-08-23/GGB - Function created.

  template<typename T, typename U>
  inline T moduloR(T val, U range)
  {
    T returnValue;

    returnValue = moduloN(val + range, range * 2);

    returnValue -= range;

    return returnValue;

  }

  /// @brief Convert a number to a long.
  /// @param[in] dbl: The value to convert.
  /// @returns the number as a long integer value
  /// @throws None.
  /// @version 2014-12-31/GGB - Function created.

  template<typename T>
  inline long INT(T dbl)
  {
    return static_cast<long>(dbl);
  }

} // namespace MCL

#endif // FUNCTIONS_HPP
