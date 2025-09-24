//*********************************************************************************************************************************
//
// PROJECT:							Maths Class Library
// FILE:								constants.h
// SUBSYSTEM:						Constants
// LANGUAGE:						C++
// TARGET OS:						All
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						PCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2011-2025 Gavin Blakeman.
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
// OVERVIEW:            Physics constants.
//
// CLASSES INCLUDED:    None.
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2011-07-29 GGB - Development of classes for openAIRS
//
//*********************************************************************************************************************************

#ifndef MCL_CONSTANTS_H
#define MCL_CONSTANTS_H

#include "config.h"

#include <cmath>

namespace MCL
{
  constexpr FP_t PI         = 3.141592653589793238462643;       // PI
  constexpr FP_t PI_2       = PI * 2;                           // 2 * PI
  constexpr FP_t D_SQRT2    = std::sqrt(2);                     // sqrt(2)
  constexpr FP_t SQRT3      = std::sqrt(3);
  constexpr FP_t D_SQRT1_2  = 1/D_SQRT2;                        // 1/sqrt(2)
  constexpr FP_t PI_DIV_2   = PI / 2;                           // PI / 2


    // Time

  FP_t const D_DPH      = 15;                               ///< Degrees per hour.
  FP_t const D_MPH      = 60;                               ///< Minutes per hour
  FP_t const D_SPH      = 3600;                             ///< Seconds per hour

    // Angles

  constexpr FP_t D_D2R      = PI / 180;                         ///< Degree to radian conversion.
  constexpr FP_t D_R2D      = 180 / PI;                         ///< Radians to degrees conversion.
  constexpr FP_t D_R2H      = 12 / PI;                          ///< Radians to hours conversion.

}

#endif // MCL_CONSTANTS_H
