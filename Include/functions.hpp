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
//                      Copyright 2014-2016 Gavin Blakeman.
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

#include <cmath>

namespace MCL
{
  /// Raise a number to power 2.
  //
  // 2014-12-31/GGB - Function created.

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

  /// Calculates the Modulo with range N
  //
  // 2013-01-13/GGB - Function created.

  template<typename T, typename U>
  inline T moduloN(T val, U range)
  {
    T returnValue;

    returnValue = val - range * std::floor(val/range);

    return returnValue;
  }

  /// Convert a number to a long.
  //
  // 2014-12-31/GGB - Function created.

  template<typename T>
  inline long INT(T dbl)
  {
    return static_cast<long>(dbl);
  }

} // namespace MCL

#endif // FUNCTIONS_HPP
