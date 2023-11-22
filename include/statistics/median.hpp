//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								median
// SUBSYSTEM:						Statistics Functions.
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	boost
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2013-2023 Gavin Blakeman.
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
// HISTORY:             2023-11-23 GGB - Added function taking a vector.
//                      2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-07-28 GGB - File Created.
//
//*********************************************************************************************************************************

#ifndef MCL_MEDIAN_HPP
#define MCL_MEDIAN_HPP

  // Standard C++ library header files

#include <algorithm>
#include <valarray>
#include <vector>

  // MCL Library header files.

#include "../config.h"
#include "../utility/sort.hpp"

namespace MCL
{

  /// @brief      Returns the median value of the data in the array.
  /// @param[in]  data:  The array to analyse for the median.
  /// @version    2023-11-23/GGB - Changed parameter to const & rather than &.
  /// @version    2016-01-15/GGB - Use static_cast rather than C-style casting.
  /// @version    2013-07-28/GGB - Function created.

  template<typename T>
  FP_t median(std::valarray<T> const &data)
  {
    size_t elements = data.size();              // Number of elements

    if (elements == 0)
    {
      return 0;
    }
    else if (elements == 1)
    {
      return data[0];
    }
    else if (elements == 2)
    {
      return static_cast<FP_t>((static_cast<FP_t>(data[0]) + static_cast<FP_t>(data[1])) / 2);
    }
    else
    {
      std::valarray<T> dataCopy(data);
      MCL::sort(std::begin(dataCopy), std::end(dataCopy));     // Sort the array

      if ( (elements & 1) == 0)
      {
        // Even

        elements = elements >> 1;   // Divide by two

        return static_cast<FP_t>((static_cast<FP_t>(dataCopy[elements - 1]) + static_cast<FP_t>(dataCopy[elements])) / 2);
      }
      else
      {
        // Odd

        elements = elements >> 1;   // Divide by two

        return static_cast<FP_t>(dataCopy[elements]);   // Return the middle number.
      };
    };
  }

  /// @brief      Returns the median value of the data in the array.
  /// @param[in]  data:  The array to analyse for the median.
  /// @returns    The median value.
  /// @version    2023-11-23/GGB - Function created.

  template<typename T>
  FP_t median(std::vector<T> const &data)
  {
    size_t elements = data.size();              // Number of elements

    if (elements == 0)
    {
      return 0;
    }
    else if (elements == 1)
    {
      return data[0];
    }
    else if (elements == 2)
    {
      return static_cast<FP_t>((static_cast<FP_t>(data[0]) + static_cast<FP_t>(data[1])) / 2);
    }
    else
    {
      std::vector<T> dataCopy(data);
      MCL::sort(std::begin(dataCopy), std::end(dataCopy));     // Sort the array

      if ( (elements & 1) == 0)
      {
        // Even

        elements = elements >> 1;   // Divide by two

        return static_cast<FP_t>((static_cast<FP_t>(dataCopy[elements - 1]) + static_cast<FP_t>(dataCopy[elements])) / 2);
      }
      else
      {
        // Odd

        elements = elements >> 1;   // Divide by two

        return static_cast<FP_t>(dataCopy[elements]);   // Return the middle number.
      };
    };
  }

}   // namespace MCL

#endif // MCL_MEDIAN_HPP
