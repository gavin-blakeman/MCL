//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								sum.hpp
// SUBSYSTEM:						Statistics Functions.
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	boost
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
// OVERVIEW:            Implementation of templated and multi-threaded statistics functions.
//
// CLASSES INCLUDED:    None
//
// FUNCTIONS INCLUDED:  sum(...)  - Sums the elements of a valarray
//
//
// HISTORY:             2015-09-22 GGB - AIRDAS 2015.09 release
//                      2014-01-13/GGB - Development of function
//
//*********************************************************************************************************************************

#ifndef MCL_STATISTICS_SUM_HPP
#define MCL_STATISTICS_SUM_HPP

  // MCL Library

#include "../config.h"

// Standard libraries

#include <cstdint>
#include <valarray>


#ifndef MCL_NOBOOST
  // Boost Library


#include "boost/optional/optional.hpp"
#include "boost/scoped_array.hpp"
#ifndef MCL_NOMT
#include "boost/thread/thread.hpp"
#endif // MCL_NOMT
#endif // MCL_NOBOOST


namespace MCL
{

#ifdef MCL_NOBOOST

  /// @brief Determines the sum of the array
  /// @param[in] data - The array to sum.
  /// @returns The sum of the data.
  /// @throws None
  /// @version 2016-01-15/GGB - Function created.

  template<typename T>
  FP_t sum(std::valarray<T> &data)
  {
    size_t index;
    FP_t returnValue = 0;

    for(index = 0; index < data.size(); index++)
    {
      returnValue += data[index];
    };

    return returnValue;
  }

#else // MCL_NOBOOST

  /// Thread function called by MCL::sum(...) to determine the sum of an array
  //
  // 2014-01-13/GGB - Function created.

  template<typename T>
  void sumThread(std::valarray<T> const &data, size_t indexStart, size_t indexEnd, FP_t &sum)
  {
    size_t index;
    sum = 0;

    for(index = indexStart; index < indexEnd; index++)
      sum += data[index];
  }

  /// Determines the sum of the array
  //
  // 2014-01-13/GGB - Function created.

  template<typename T>
  FP_t sum(std::valarray<T> &data)
  {
    size_t numberOfThreads;
    size_t threadNumber;
    size_t stepSize;
    boost::thread_group threadGroup;
    boost::thread *thread;
    size_t indexBegin = 0, indexEnd = 0;
    size_t index;
    FP_t returnValue = 0;
    size_t count = data.size();

    if (count != 0)
    {
       // Ensure that we are using a reasonable number of threads. Maximise the number of threads to the number of values

      numberOfThreads = count / 1000;
      if (numberOfThreads == 0)
        numberOfThreads = 1;
      else if (numberOfThreads > maxThreads)
        numberOfThreads = maxThreads;

      stepSize = count / numberOfThreads;

      boost::scoped_array<FP_t> sums(new FP_t[numberOfThreads]);

        // Spawn the threads.

      for (threadNumber = 0; threadNumber < numberOfThreads; threadNumber++)
      {
        indexBegin = indexEnd;
        if (threadNumber == (numberOfThreads - 1) )
          indexEnd = count;
        else
          indexEnd += stepSize;
        thread = new boost::thread(&sumThread<T>, boost::cref(data), indexBegin, indexEnd, boost::ref(sums[threadNumber]));
        threadGroup.add_thread(thread);
        thread = nullptr;
      };

      threadGroup.join_all();     // Wait for all the threads to finish.

      for(index = 0; index < numberOfThreads; index++)
        returnValue += sums[index];

      return returnValue;
    };
  }

#endif // MCL_NOBOOST

}  // namespace MCL

#endif // MCL_STATISTICS_SUM_HPP
