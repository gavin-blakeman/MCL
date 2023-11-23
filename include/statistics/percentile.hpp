//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								percentile
// SUBSYSTEM:						Statistics Functions.
// LANGUAGE:						C++
// TARGET OS:						None.
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2022-2023 Gavin Blakeman.
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
// OVERVIEW:            Implementation of templated and multi-threaded statistics functions.
//
// CLASSES INCLUDED:    None
//
// FUNCTIONS INCLUDED:  median(...)
//
// HISTORY:             2022-12-02 GGB - File Created.
//
//*********************************************************************************************************************************

#ifndef PERCENTILE_HPP
#define PERCENTILE_HPP

  // Standard C++ library

#include <algorithm>
#include <cmath>
#include <valarray>
#include <vector>

#include "../config.h"

namespace MCL
{

  /// @brief      Returns the percentile requested from the array.
  /// @param[in]  va: The valarray to find the percentile.
  /// @param[in]  p: The percentile to find. [0; 100]
  /// @throws
  /// @version    2022-12-02/GGB - Function created.

  template<typename T, typename U>
  FP_t percentile(std::valarray<T> va, U p)
  {
    if (p == 0)
    {
      return 0;
    }
    else if (va.size() == 0)
    {
      return 0;
    }
    else
    {
      std::size_t s1 = 0;
      std::size_t s2 = 0;

      std::sort(std::begin(va), std::end(va));

      FP_t d = static_cast<FP_t>(p) * static_cast<FP_t>(va.size() + 1);
      s1 = static_cast<std::size_t>(std::floor(d)) - 1;
      s2 = static_cast<std::size_t>(std::ceil(d)) - 1;

      s1 = std::min(s1, va.size() - 1);
      s2 = std::min(s2, va.size() - 1);

      if (s1 == s2)
      {
        return va[s1];
      }
      else
      {
        d -= std::floor(d);
        d *= (va[s2] - va[s1]);
        return va[s1] + d;
      }
    };
  }

  /// @brief      Returns the percentile requested from the array.
  /// @param[in]  v: The vector of values. to find the percentile.
  /// @param[in]  p: The percentile to find. [0; 100]
  /// @throws
  /// @version    2023-11-23/GGB - Function created.

  template<typename T, typename U>
  FP_t percentile(std::vector<T> v, U p)
  {
    if (p == 0)
    {
      return 0;
    }
    else if (v.size() == 0)
    {
      return 0;
    }
    else
    {
      std::size_t s1 = 0;
      std::size_t s2 = 0;

      std::sort(std::begin(v), std::end(v));

      FP_t d = static_cast<FP_t>(p) * static_cast<FP_t>(v.size() + 1);
      s1 = static_cast<std::size_t>(std::floor(d)) - 1;
      s2 = static_cast<std::size_t>(std::ceil(d)) - 1;

      s1 = std::min(s1, v.size() - 1);
      s2 = std::min(s2, v.size() - 1);

      if (s1 == s2)
      {
        return v[s1];
      }
      else
      {
        d -= std::floor(d);
        d *= (v[s2] - v[s1]);
        return v[s1] + d;
      }
    };
  }


} // namespace

#endif // PERCENTILE_HPP
