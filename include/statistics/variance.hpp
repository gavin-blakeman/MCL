//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								Variance
// SUBSYSTEM:						Statistics Functions - Variance
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	boost
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2013-2022 Gavin Blakeman.
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
// FUNCTIONS INCLUDED:  variance(...)
//
//
// HISTORY:             2018-09-20 GGB - Refactoring to use std::uniqu_ptr
//                      2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-08-02/GGB - Updated to be 64bit compliant.
//                      2013-03-22/GGB - Function tested.
//                      2013-03-17 GGB - File created.
//
//*********************************************************************************************************************************

#ifndef MCL_STATISTICS_VARIANCE_HPP
#define MCL_STATISTICS_VARIANCE_HPP

  // Standard C++ library header files

#include <cstdint>
#include <memory>
#include <optional>
#include <thread>
#include <valarray>
#include <vector>

  // MCL Library

#include "../config.h"
#include "../functions.hpp"

  // Boost Library

#ifndef MCL_NOBOOST
#ifndef MCL_NOMT
#include "boost/thread/thread.hpp"
#endif // MCL_NOMT
#endif // MCL_NOBOOST

namespace MCL
{
#ifdef MCL_NOMT

  /// @brief Multi-threaded function to calculate the variance
  //
  /// @version 2016-01-15/GGB - Function created.

  template<typename T>
  bool variance(T *data, size_t dataCount, T &returnValue)
  {
    size_t index;
    T sum = 0, sumsq = 0, mean;

    if (dataCount == 0)
    {
      return false;
    }
    else if (dataCount == 1)
    {
      returnValue = 0;
      return true;
    }
    else
    {
      for (index = 0; index < dataCount; index++)
      {
        sum += data[index];
        sumsq += MCL::pow2(data[index]);
      };

      mean = sum / dataCount;
      returnValue = (sumsq - dataCount * MCL::pow2(mean))/(dataCount - 1);

      return true;
    };
  }

#else   // MCL_NOMT

  /// @brief Variance function called by MCL::variance(...) to determine the variance of an array
  /// @param[in] data:
  /// @version 2013-03-21/GGB - Function created.

  template<typename T>
  void varianceThread(T *data, size_t indexStart, size_t indexEnd, FP_t &mean, FP_t &M2, size_t &count)
  {
    size_t index;

    FP_t delta;

    count = 0;
    M2 = 0;
    mean = 0;

    for(index = indexStart; index < indexEnd; index++)
    {
      ++count;
      delta = data[index] - mean;
      mean += delta / count;
      M2 += delta * (data[index] - mean);
    };
  }

  /// @brief Variance function called by MCL::variance(...) to determine the variance of a valarray
  /// @param[in] data:
  /// @version 2013-03-21/GGB - Function created.

  template<typename T>
  void varianceThreadVA(std::valarray<T> const &data, size_t indexStart, size_t indexEnd, FP_t &mean, FP_t &M2, size_t &count)
  {
    size_t index;

    FP_t delta;

    count = 0;
    M2 = 0;
    mean = 0;

    for(index = indexStart; index < indexEnd; index++)
    {
      ++count;
      delta = data[index] - mean;
      mean += delta / count;
      M2 += delta * (data[index] - mean);
    };
  }

  /// @brief Multi-threaded function to calculate the variance
  /// @param[in] data: Pointer to the data.
  /// @param[in] dataCount: The number of data points.
  /// @throws
  /// @version 2018-09-20/GGB - Updated to use std::unique_ptr instead of boost scoped arrays.
  /// @version 2015-08-30/GGB - Function created.

  template<typename T>
  std::optional<FP_t> variance(T *data, size_t dataCount)
  {
    size_t numberOfThreads;
    size_t threadNumber;
    size_t stepSize;
    boost::thread_group threadGroup;
    boost::thread *thread;
    size_t indexBegin, indexEnd = 0;
    size_t index;

    if (dataCount == 0)
    {
      return std::optional<FP_t>();
    }
    else if (dataCount == 1)
    {
      return std::optional<FP_t>(0);
    }
    else
    {
       // Ensure that we are using a reasonable number of threads. Maximise the number of threads to the number of values

      numberOfThreads = dataCount / 1000;
      if (numberOfThreads == 0)
      {
        numberOfThreads = 1;
      }
      else if (numberOfThreads > maxThreads)
      {
        numberOfThreads = maxThreads;
      }

      stepSize = dataCount / numberOfThreads;

      std::unique_ptr<size_t []> counts(new size_t[numberOfThreads]);
      std::unique_ptr<FP_t []> means(new FP_t[numberOfThreads]);
      std::unique_ptr<FP_t []> M2s(new FP_t[numberOfThreads]);

        // Spawn the threads to calculate the variance of each thread.

      for (threadNumber = 0; threadNumber < numberOfThreads; threadNumber++)
      {
        indexBegin = indexEnd;
        if (threadNumber == (numberOfThreads -1) )
        {
          indexEnd = dataCount;
        }
        else
        {
          indexEnd += stepSize;
        };

        thread = new boost::thread(&varianceThread<T>, boost::cref(data), indexBegin, indexEnd,
                                   boost::ref(means[threadNumber]), boost::ref(M2s[threadNumber]),
                                   boost::ref(counts[threadNumber]));
        threadGroup.add_thread(thread);
        thread = nullptr;
      };

      threadGroup.join_all();     // Wait for all the threads to finish.

        // Now calculate the variance from the variances.

      FP_t count = 0;
      FP_t variance = 0;
      FP_t delta = 0;
      FP_t mean = 0;
      FP_t M2;

      if (numberOfThreads == 1)
      {
        variance = M2s[0] / (counts[0] - 1);
      }
      else
      {
        M2 = M2s[0];
        mean = means[0];
        count = counts[0];

        for(index = 1; index < numberOfThreads; index++)
        {
          delta = means[index] - mean;
          mean = (count * mean + counts[index] * means[index]) / (count + counts[index]);
          M2 = M2 + M2s[index] + pow2(delta) * count * counts[index] / (count + counts[index]);
          count += counts[index];
        };

        variance = M2 / (count - 1);
      };

      return std::optional<FP_t>(variance);
    };
  }

  /// @brief Multi-threaded function to calculate the variance of a valarray
  /// @param[in] data: The valarray
  /// @throws
  /// @version 2022-11-29/GGB - Function created.

  template<typename T>
  FP_t variance(std::valarray<T> const &va)
  {
    size_t numberOfThreads;
    size_t threadNumber;
    size_t stepSize;
    std::vector<std::thread *> threadGroup;
    std::thread *thread;
    size_t indexBegin, indexEnd = 0;
    size_t index;

    if (va.size() <= 1)
    {
      return 0;
    }
    else
    {
       // Ensure that we are using a reasonable number of threads. Maximise the number of threads to the number of values

      numberOfThreads = std::max(std::min(size_t {1}, va.size() / 1000), maxThreads);

      stepSize = va.size() / numberOfThreads;

      std::unique_ptr<size_t []> counts(new size_t[numberOfThreads]);
      std::unique_ptr<FP_t []> means(new FP_t[numberOfThreads]);
      std::unique_ptr<FP_t []> M2s(new FP_t[numberOfThreads]);

        // Spawn the threads to calculate the variance of each thread.

      for (threadNumber = 0; threadNumber < numberOfThreads; threadNumber++)
      {
        indexBegin = indexEnd;
        if (threadNumber == (numberOfThreads -1) )
        {
          indexEnd = va.size();
        }
        else
        {
          indexEnd += stepSize;
        };

        thread = new std::thread(&varianceThreadVA<T>, boost::cref(va), indexBegin, indexEnd,
                                   boost::ref(means[threadNumber]), boost::ref(M2s[threadNumber]),
                                   boost::ref(counts[threadNumber]));
        threadGroup.push_back(thread);
        thread = nullptr;
      };

      for (auto &thread : threadGroup)
      {
        thread->join();
      }

        // Now calculate the variance from the variances.

      FP_t count = 0;
      FP_t variance = 0;
      FP_t delta = 0;
      FP_t mean = 0;
      FP_t M2;

      if (numberOfThreads == 1)
      {
        variance = M2s[0] / (counts[0] - 1);
      }
      else
      {
        M2 = M2s[0];
        mean = means[0];
        count = counts[0];

        for(index = 1; index < numberOfThreads; index++)
        {
          delta = means[index] - mean;
          mean = (count * mean + counts[index] * means[index]) / (count + counts[index]);
          M2 = M2 + M2s[index] + pow2(delta) * count * counts[index] / (count + counts[index]);
          count += counts[index];
        };

        variance = M2 / (count - 1);
      };

      return variance;
    };
  }

#endif
} // namespace MCL

#endif // MCL_STATISTICS_VARIANCE_HPP
