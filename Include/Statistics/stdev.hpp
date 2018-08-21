//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								StandardDeviation
// SUBSYSTEM:						Statistics Functions - Standard Deviation()
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	boost
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2013-2018 Gavin Blakeman.
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
// FUNCTIONS INCLUDED:  stdev(...)
//
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-08-02/GGB - Updated to be 64bit compliant.
//                      2013-03-22/GGB - Function tested.
//                      2013-03-17 GGB - File created.
//
//*********************************************************************************************************************************

#ifndef MCL_STANDARDDEVIATION_HPP
#define MCL_STANDARDDEVIATION_HPP

  // Standard libraries

#include <cstdint>
#include <optional>
#include <valarray>

  // MCL Library

#include "../config.h"
#include "variance.hpp"

#ifndef MCL_NOBOOST

#ifndef MCL_NOMT
#include "boost/thread/thread.hpp"
#endif // MCL_NOMT

#endif // MCL_NOBOOST



namespace MCL
{
#ifdef MCL_NOMT

  /// Calculates the stdev of the data using the multi-threaded variance.
  //
  // 2013-03-21/GGB - Function created.

  template<typename T>
  bool stdev(std::valarray<T> const &data, T &returnValue)
  {
    if (variance(data, data.size(), returnValue))
    {
      returnValue = std::sqrt(returnValue);
    }
    else
    {
      return false;
    }
  }

  /// @brief Calculates the stdev of the data using the multi-threaded variance.
  /// @version 2013-03-21/GGB - Function created.

  template<typename T>
  bool stdev(T * data, size_t elementCount, T &returnValue)
  {
    if (variance(data, data.size(), returnValue))
    {
      returnValue = std::sqrt(returnValue);
    }
    else
    {
      return false;
    }
  }

#else // MCL_NOMT

  /// Calculates the stdev of the data using the multi-threaded variance.
  //
  // 2013-03-21/GGB - Function created.

  template<typename T>
  std::optional<FP_t> stdev(std::valarray<T> const &data)
  {
    std::optional<FP_t> returnValue(sqrt(*variance(data)));

    return returnValue;
  }

  /// @brief Calculates the stdev of the data using the multi-threaded variance.
  /// @version 2013-03-21/GGB - Function created.

  template<typename T>
  std::optional<FP_t> stdev(T * data, size_t elementCount)
  {
    std::optional<FP_t> returnValue(sqrt(*variance(data, elementCount)));

    return returnValue;
  }

#endif // MCL_NOMT

}

#endif // MCL_STANDARDDEVIATION_HPP
