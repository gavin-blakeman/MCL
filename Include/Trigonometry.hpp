//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								Trigonometry.h
// SUBSYSTEM:						Trigonometry functions
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman. (GGB)
// LICENSE:             GPLv2
//
//                      Copyright 2012-2017 Gavin Blakeman.
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
// OVERVIEW:            A number of trigonometry related functions.
//                      All functions have return types of FP_t.
//
// CLASSES INCLUDED:    None
//
// FUNCTIONS INCLUDED:  cosect(...)
//                      sec(...)
//                      cot(...)
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2014-12-31 GGB - Convert all functions to templated functions and filename to Trigonometry.hpp
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-03-22 GGB - astroManager 2013.03 release.
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2012-12-26 GGB - Development of class for openAIRS application.
//
//*********************************************************************************************************************************

#ifndef MCL_TRIGONOMETRY_HPP
#define MCL_TRIGONOMETRY_HPP

#include <cmath>

#include "MCLError.h"
#include "config.h"

namespace MCL
{
  /// @brief Calculate the cosec (1/sin) of an angle.
  /// @param[in] a - Angle in radians.
  /// @returns cosec(a)
  /// @throws
  /// @version 2014-12-31/GGB - Converted to templated function.

  template<typename T>
  inline FP_t cosec(T a)
  {
    return static_cast<FP_t>(1/std::sin(static_cast<double>(a)));
  }

  /// @brief Calculate the sec (1/cos) of an angle.
  /// @param[in] a - Angle in radians
  /// @returns sec(a)
  /// @throws
  /// @version 2014-12-31/GGB - Converted to templated function.

  template<typename T>
  inline FP_t sec(T a)
  {
    return static_cast<FP_t>(1/std::cos(static_cast<double>(a)));
  }

  /// @ brief Calculate the cot (1/tan) of an angle.
  /// @param[in] a - Angle in radians.
  /// @returns cot(a)
  /// @throws
  /// @version 2014-12-31/GGB - Converted to templated function.

  template<typename T>
  inline FP_t cot(T a)
  {
    return static_cast<FP_t>(1/std::tan(static_cast<double>(a)));
  }

} // namespace

#endif // MCL_TRIGONOMETRY_HPP
