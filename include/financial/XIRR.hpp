//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								XIRR.hpp
// SUBSYSTEM:						Financial Functions.
// LANGUAGE:						C++
// TARGET OS:						None.
// LIBRARY DEPENDANCE:	None
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2023 Gavin Blakeman.
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
// FUNCTIONS INCLUDED:  XIRR
//
//
// HISTORY:             2023-07-18 GGB - File Created
//
//*********************************************************************************************************************************

#ifndef XIRR_H
#define XIRR_H

  // Standard C++ library

#include <chrono>
#include <vector>

  // MCL library

namespace MCL
{

  using date_t = std::chrono::time_point<std::chrono::system_clock, std::chrono::days>;
  using dateVector_t = std::vector<date_t>;

  template<typename T>
  T XIRR(dateVector_t const &dateVector, std::vector<T> const &valueVector)
  {

  }
}

#endif // XIRR_H
