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
//                      Copyright 2011-2017 Gavin Blakeman.
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
// HISTORY:             2015-09-22 GGB - AIRDAS 2015.09 release
//                      2011-07-29   - Development of classes for openAIRS
//
//*********************************************************************************************************************************

#ifndef MCL_CONSTANTS_H
#define MCL_CONSTANTS_H

#include "config.h"

namespace MCL
{
  const FP_t D_PI       = 3.141592653589793238462643;       // PI
  const FP_t D_2PI      = 6.283185307179586476925287;       // 2 * PI
  const FP_t D_SQRT2    = 1.414213562373095048801688;       // sqrt(2)
  const FP_t D_SQRT1_2  = 0.707106781186547524401;          // 1/sqrt(2)
  const FP_t D_PIDIV2   = D_PI / 2;                         // PI / 2

    // Time

  FP_t const K_DPH      = 15;                               ///< Degrees per hour.
  FP_t const K_MPH      = 60;                               ///< Minutes per hour
  FP_t const K_SPH      = 3600;                             ///< Seconds per hour

    // Angles

  FP_t const K_D2R      = D_PI / 180;                       ///< Degree to radian conversion.
  FP_t const K_R2D      = 180 / D_PI;                       ///< Radians to degrees conversion.
  FP_t const K_R2H      = 12 / D_PI;                        ///< Radians to hours conversion.

}

#endif // MCL_CONSTANTS_H
