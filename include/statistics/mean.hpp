﻿//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								Mean.hpp
// SUBSYSTEM:						Statistics Functions.
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	GCL
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2012-2024 Gavin Blakeman.
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
// FUNCTIONS INCLUDED:  mean(...)
//                      mean(valarray)
//
//
// HISTORY:             2023-11-14/GGB - Added function for running mean calculation.
//                      2015-09-22 GGB - astroManager 2015.09 release
//                      2015-07-10/GGB - Added function mean(T *)
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-08-02/GGB - Updated to be 64bit compliant.
//                      2013-03-22/GGB - Mean function tested against known data.
//                      2012-11-29 GGB - Development of file for astroManager application.
//
//*********************************************************************************************************************************

#ifndef MCL_STATISTICS_MEAN_HPP
#define MCL_STATISTICS_MEAN_HPP

  // Standard C++ library header files

#include <algorithm>
#include <cstdint>
#include <memory>
#include <optional>
#include <thread>
#include <valarray>
#include <utility>
#include <vector>

  // Miscellaneous library header files

#include <GCL>

  // MCL Library header files

#include "../config.h"

/// @file
/// The file provides a number of templated mean functions. These functions are provided in bost single-thread and multi-threaded
/// versions.
/// 1. mean(valarray<T>)
/// 2. mean(T *)

namespace MCL
{

  /// @brief      Calculate the next mean of an running samples.
  /// @param[in]  mN1: The previous mean.
  /// @param[in]  Kn: The N'th sample.
  /// @param[in]  Nk: The number of samples to this point.
  /// @returns    The updated mean value.
  /// @throws
  /// @version    2023-11-14/GGB - Function created.

  template<typename T, typename U, typename V>
  T mean(T mN1, V kN, U Nk)
  {
    return mN1 + (static_cast<T>(kN) - mN1) / static_cast<T>(Nk);
  }

  /// @brief      Returns the weighted mean of data supplied as two vectors.
  /// @param[in]  N: vector containing the values.
  /// @param[in]  W: vector containing the weights.
  /// @returns    double value containing the weighted mean.
  /// @throws
  /// @version    2023-11-29/GGB - Function created.

  template<typename T, typename U>
  double mean_w(std::vector<T> const &N, std::vector<U> const &W)
  {
    RUNTIME_ASSERT(N.size() == W.size(), "mean_w requires both vectors to be the same size.");
    RUNTIME_ASSERT(N.size() != 0, "mean_w cannot calulate mean with no data.");

    double sN = 0;
    double sW = 0;

    for (std::size_t indx = 0; indx < N.size(); indx++)
    {
      sN += N[indx] * W[indx];
      sW += W[indx];
    }

    RUNTIME_ASSERT(sW != 0, "Sum of weights in a weighted mean cannot be zero.");

    return sN / sW;
  }

  /// @brief      Returns the weighted mean of data supplied as pairs in a vector.
  /// @param[in]  D: a vector of pairs. THe first value in the pair is the N and the second is the W.
  /// @returns    double value containing the weighted mean.
  /// @throws
  /// @version    2023-11-29/GGB - Function created.

  template<typename T, typename U>
  double mean_w(std::vector<std::pair<T, U>> const &D)
  {
    RUNTIME_ASSERT(D.size() > 0, "Unable to calculate weighted mean with no data.");

    double sN = 0;
    double sW  = 0;

    for (auto const &d : D)
    {
      sN += d.first * d.second;
      sW += d.second;
    };

    RUNTIME_ASSERT(sW != 0, "Sum of weights in a weighted mean cannot be zero.");

    sN /= sW;

    return sN;
  }

  /// @brief Calculate the mean of a c-style array of data.
  /// @param[in] data - The data array
  /// @param[in] len - The number of samples in the array
  /// @param[out] returnValue - The calculated mean.
  /// @returns true = success
  /// @returns false = failure.
  /// @throws None.
  /// @note This function is multi-threaded.
  /// @version 2016-01-15/GGB - Function created.

  template<typename T>
  bool mean(T *data, size_t len, T &returnValue)
  {
    size_t index;

    returnValue = 0;      // Set the value to zero and use for the calculations.

    if (len == 0)
    {
      return false;
    }
    else
    {
      for(index = 0; index < len;)
      {
        returnValue += (data[index] - returnValue) / (++index);
      };

      return true;
    };
  }

  /// @brief    Calculates the mean of a vector.
  /// @param[in]  v: The vector to calculate.
  /// @returns    An optional containing the mean. (The mean is undefined if v.size() == 0)
  /// @throws
  /// @version    2024-12-21/GGB - Function created.

  template<typename T>
  std::optional<T> mean(std::vector<T> const &v)
  {
    if (v.empty())
    {
      return std::optional<T>{};
    }
    else if (v.size() == 1)
    {
      return std::optional<T>{v[0]};
    }
    else
    {
      FP_t m = 0;
      std::size_t cnt = 0;

      for (auto const &val: v)
      {
        m = mean(m, val, ++cnt);
      };

      return std::optional<T>{static_cast<T>(m)};
    }
  }

  /// @brief Thread function called by MCL::mean to determine the mean of an array
  /// @param[in] data: The data to calculate the mean of
  /// @param[in] indexStart: The starting index in the array
  /// @param[in] indexEnd: One more than the last index to include in the calculation
  /// @param[out] mean: The calculated mean
  /// @param[out] count: The number of samples counted.
  /// @throws None.
  /// @version 2013-03-11/GGB - Converted to use std::valarray<> as storage type.
  /// @version 2012-11-29/GGB - Function created.

  template<typename T>
  void meanThread(T *data, size_t indexStart, size_t indexEnd, FP_t &mean, size_t &count)
  {
    size_t index;
    mean = 0;
    count = 0;

    for(index = indexStart; index < indexEnd; index++)
    {
      mean += (data[index] - mean) / (++count);
    };
  }

  /// @brief Thread function called by MCL::mean(valarray) to determine the mean of an array
  /// @param[in] data: The data to calculate the mean of
  /// @param[in] indexStart: The starting index in the array
  /// @param[in] indexEnd: One more than the last index to include in the calculation
  /// @param[out] mean: The calculated mean
  /// @param[out] count: The number of samples counted.
  /// @throws None.
  /// @version 2022-11-29/GGB - Function created.

  template<typename T>
  void meanThreadVA(std::valarray<T> &data, size_t indexStart, size_t indexEnd, FP_t &mean, size_t &count)
  {
    size_t index;
    mean = 0;
    count = 0;

    for(index = indexStart; index < indexEnd; index++)
    {
      mean += (data[index] - mean) / (++count);
    };
  }


  /// @brief Calculate the mean of a c-style array of data.
  /// @param[in] data: The data array
  /// @param[in] len: The number of samples in the array
  /// @returns The mean of the values in the array.
  /// @throws None.
  /// @note This function is multi-threaded.
  /// @version 2018-09-20/GGB - Updated to use std::unique_ptr instead of boost scoped arrays.
  /// @version 2015-07-10/GGB - Function created.

  template<typename T>
  std::optional<FP_t> mean(T *data, size_t len)
  {
    size_t numberOfThreads;
    size_t threadNumber;
    size_t stepSize;
    std::vector<std::thread> threadGroup;
    size_t indexBegin = 0, indexEnd = 0;
    size_t index;
    FP_t returnValue = 0;
    size_t count = len;

    if (count == 0)
    {
      return std::optional<FP_t>();
    }
    else
    {
       // Ensure that we are using a reasonable number of threads. Maximise the number of threads to the number of values

      numberOfThreads = count / 1000;
      if (numberOfThreads == 0)
      {
        numberOfThreads = 1;
      }
      else if (numberOfThreads > maxThreads)
      {
        numberOfThreads = maxThreads;
      };

      stepSize = count / numberOfThreads;

      std::unique_ptr<size_t []> counts(new size_t[numberOfThreads]);
      std::unique_ptr<FP_t []> means(new FP_t[numberOfThreads]);

        // Spawn the threads.

      for (threadNumber = 0; threadNumber < numberOfThreads; threadNumber++)
      {
        indexBegin = indexEnd;
        if (threadNumber == (numberOfThreads - 1) )
        {
          indexEnd = count;
        }
        else
        {
          indexEnd += stepSize;
        };
        threadGroup.emplace_back(&meanThread<T>, data, indexBegin, indexEnd, std::ref(means[threadNumber]), std::ref(counts[threadNumber]));
      };

      for (auto &thread: threadGroup)
      {
        thread.join();     // Wait for all the threads to finish.
      };

      for(index = 0; index < numberOfThreads; index++)
      {
        returnValue += means[index] * counts[index] / count;
      };

      return std::optional<FP_t>(returnValue);
    };
  }

  /// @brief Calculate the mean of a valarray
  /// @param[in] data: The data array
  /// @returns The mean of the values in the array.
  /// @throws None.
  /// @note This function is multi-threaded.
  /// @version 2022-11-29/GGB - Function created.

  template<typename T>
  FP_t mean(std::valarray<T> &va)
  {
    size_t numberOfThreads;
    size_t threadNumber;
    size_t stepSize;
    std::vector<std::thread *> threadGroup;
    std::thread *thread;
    size_t indexBegin = 0, indexEnd = 0;
    size_t index;
    FP_t returnValue = 0;

    if (va.size() != 0)
    {
       // Ensure that we are using a reasonable number of threads. Maximise the number of threads to the number of values

      numberOfThreads = std::min(std::max(std::size_t {1}, va.size() / 1000), maxThreads);

      stepSize = va.size() / numberOfThreads;

      std::unique_ptr<size_t []> counts(new size_t[numberOfThreads]);
      std::unique_ptr<FP_t []> means(new FP_t[numberOfThreads]);

        // Spawn the threads.

      for (threadNumber = 0; threadNumber < numberOfThreads; threadNumber++)
      {
        indexBegin = indexEnd;
        if (threadNumber == (numberOfThreads - 1) )
        {
          indexEnd = va.size();
        }
        else
        {
          indexEnd += stepSize;
        };
        thread = new std::thread(&meanThreadVA<T>, boost::ref(va), indexBegin, indexEnd,
                                 boost::ref(means[threadNumber]), boost::ref(counts[threadNumber]));
        threadGroup.push_back(thread);
        thread = nullptr;
      };

      for (auto &thread: threadGroup)
      {
        thread->join();
      };

      for(index = 0; index < numberOfThreads; index++)
      {
        returnValue += means[index] * counts[index] / va.size();
      };

      return returnValue;
    }
    else
    {
      return 0;
    }
  }

}  // namespace MCL

#endif // MCL_STATISTICS_MEAN_HPP
