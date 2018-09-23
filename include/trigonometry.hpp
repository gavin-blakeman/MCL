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
//                      Copyright 2012-2018 Gavin Blakeman.
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

  // Standard C++ library header files.

#include <cmath>

  // MCL Library header files.

#include "error.h"
#include "config.h"
#include "functions.hpp"

namespace MCL
{
  /// @brief Calculate the cosec (1/sin) of an angle.
  /// @param[in] a: Angle in radians.
  /// @returns cosec(a)
  /// @throws MCL::divide_by_zero.
  /// @version 2018-08-20/GGB - Added test for zero and throw on error.
  /// @version 2014-12-31/GGB - Converted to templated function.

  template<typename T>
  inline FP_t cosec(T a)
  {
    FP_t sinValue = std::sin(static_cast<double>(a));

    if (sinValue != 0)
    {
      return static_cast<FP_t>(1/sinValue);
    }
    else
    {
      throw divide_by_zero("Divide by zero in function cosec(a)");
    }
  }

  /// @brief Calculate the sec (1/cos) of an angle.
  /// @param[in] a: Angle in radians
  /// @returns sec(a)
  /// @throws MCL::divide_by_zero.
  /// @version 2018-08-20/GGB - Added test for zero and throw on error.
  /// @version 2014-12-31/GGB - Converted to templated function.

  template<typename T>
  inline FP_t sec(T a)
  {
    FP_t cosValue = std::cos(static_cast<double>(a));

    if (cosValue != 0)
    {
      return static_cast<FP_t>(1/cosValue);
    }
    else
    {
      throw divide_by_zero("Divide by zero in function sec(a)");
    }
  }

  /// @ brief Calculate the cot (1/tan) of an angle.
  /// @param[in] a: Angle in radians.
  /// @returns cot(a)
  /// @throws MCL::divide_by_zero.
  /// @version 2018-08-20/GGB - Added test for zero and throw on error.
  /// @version 2014-12-31/GGB - Converted to templated function.

  template<typename T>
  inline FP_t cot(T a)
  {
    a = moduloN(a, PI_2);     // Limit the value to a range.

    if (a == PI_DIV_2 || a == (PI_DIV_2 * 3) )
    {
      return 0;     // While the tan function returns out of range at these points, the cot function is actually defined as zero.
    }
    else
    {
      FP_t tanValue = std::tan(static_cast<double>(a));

      if (tanValue != 0)
      {
        return static_cast<FP_t>(1/tanValue);
      }
      else
      {
        throw divide_by_zero("Divide by zero in function cot(a)");
      };
    };
  }

} // namespace

#endif // MCL_TRIGONOMETRY_HPP
