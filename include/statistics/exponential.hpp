//*************************************************************************************************
//
// PROJECT:							MCL (Math Class Library)
// FILE:								exponential
// SUBSYSTEM:           statistics/exponential
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2022 Gavin Blakeman.
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
// OVERVIEW:            Implementation of shared definintions.
//
// HISTORY:             2022-12-03 GGB - File created.
//
//*************************************************************************************************

#ifndef EXPONENTIAL_HPP
#define EXPONENTIAL_HPP

  // Standard C++ library

#include <cmath>

  // MCL Library

#include "../config.h"

  // Miscellaneous libraries

#include <GCL>

/// @brief Retuns the exponential distribution value
/// @param[in] x: The probablity value.
/// @param[in] l: lambda value
/// @returns the inverse exponential value.
/// @throws
/// @version 2022-12-03/GGB - Function created.

FP_t exponential_inverse(FP_t x, FP_t l)
{
  RUNTIME_ASSERT(l != 0, "Parameter l cannot be zero");
  return -std::log(1-x) / l;
}

#endif // EXPONENTIAL_HPP
