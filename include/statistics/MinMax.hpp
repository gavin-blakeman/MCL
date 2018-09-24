//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								Mean.hpp
// SUBSYSTEM:						Statistics Functions.
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	boost
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2012-2018 Gavin Blakeman.
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
// FUNCTIONS INCLUDED:  MinMax(...)
//
//
// HISTORY:             2018-09-19 GGB - Change boost::optional to std::optional
//                      2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-08-02/GGB - Updated to 64bit compliance.
//                      2013-03-20/GGB - astroManager 2013.03 release.
//                      2013-01-22/GGB - astroManager 0000.00 release.
//                      2012-11-30 GGB - Development of file for openAIRS application.
//
//*********************************************************************************************************************************

#ifndef MCL_STATISTICS_MINMAX_HPP
#define MCL_STATISTICS_MINMAX_HPP

  // Standard C++ library header files.

#include <cstdint>
#include <memory>
#include <optional>
#include <tuple>

  // MCL Library

#include "../config.h"


#ifndef MCL_NOBOOST
  // Boost Library
#ifndef MCL_NOMT
#include "boost/thread/thread.hpp"
#endif //MCL_NOMT

#endif // MCL_NOBOOST

namespace MCL
{

#ifdef MCL_NOBOOST

  /// @brief Function to determine the maximum value in an array.
  /// @param[out] maxValue - The maximum value in the array.
  /// @returns true - Function successfull
  /// @returns false - Function failed.
  /// @version 2016-01-15/GGB - Function created.

  template<typename T>
  bool max(std::valarray<T> const &data, T &maxValue)
  {
    size_t index;

    if (data.size() == 0)
    {
      return false;
    }
    else
    {

      maxValue = data[0];

      for(index = 1; index < data.size(); index++)
      {
        if (data[index] > max)
        {
          max = data[index];
        }
      };

      return true;
    };
  }

  /// @brief Function to determine the minimum value in an array.
  //
  /// @version 2016-01-15/GGB - Function created.

  template<typename T>
  bool min(std::valarray<T> const &data, T &minValue)
  {
    size_t index;

    if (data.size() == 0)
    {
      return false;
    }
    else
    {
      minValue = data[0];

      for(index = 1; index < data.size(); index++)
      {
        if (data[index] < min)
        {
          min = data[index];
        };
      };

      return true;
    };
  }

  /// @brief Thread function to determine the minimum and maximum value in an array.
  //
  // 2013-08-02/GGB - 1) Converted to use type T for return values.
  //                  2) Changed parameter to const &
  // 2013-03-11/GGB - Converted to use std::valarray<> as storage type.
  // 2012-11-30/GGB - Function created.

  template<typename T>
  void minmaxThread(T *data, size_t indexStart, size_t indexEnd, T &min, T &max)
  {
    size_t index;

    max = min = data[indexStart];


  }

  /// @brief Function to determine the minimum value in an array.
  /// @param[in] data - The data array
  /// @param[in] dataCount - The number of elements in the array.
  /// @returns true - success
  /// @returns false - failure
  /// @throws None.
  /// @version 2016-01-15/GGB - Function created.

  template<typename T>
  bool minmax(T *data, size_t dataCount, T &minValue, T &maxValue)
  {
    size_t index;

    if (dataCount == 0)
    {
      return false;
    }
    else
    {
      minValue = maxValue = data[0];

      for(index = 1; index < dataCount; index++)
      {
        if (data[index] < min)
        {
          min = data[index];
        };

        if (data[index] > max)
        {
          max = data[index];
        };
      };

      return true;
    };
  }

#else // MCL_NOBOOST

  /// @brief Thread function to determine the maximum value in an array.
  /// @param[in] data:
  /// @version 2013-08-02/GGB - Updated to use valarray const & and T for data.
  /// @version 2012-11-30/GGB - Function created.

  template<typename T>
  void maxThread(std::valarray<T> const &data, size_t indexStart, size_t indexEnd, T &max)
  {
    size_t index;

    max = data[indexStart++];

    for(index = indexStart; index < indexEnd; index++)
    {
      if (data[index] > max)
      {
        max = data[index];
      }
    }
  }

  /// @brief Function to determine the maximum value in an array.
  /// @param[in] data: The valarray with the data.
  /// @version 2018-09-19/GGB - Use and return std::optional instead of boost::optional.
  /// @version 2013-08-02/GGB - Updated to use valarray const & and T for data.
  /// @version 2012-11-30/GGB - Function created.

  template<typename T>
  std::optional<T> max(std::valarray<T> const &data)
  {
    size_t numberOfThreads;
    size_t threadNumber;
    size_t stepSize;
    boost::thread_group threadGroup;
    boost::thread *thread;

    size_t indexBegin, indexEnd = 0;
    size_t index;
    T returnValue = 0;

    if (data.size() == 0)
    {
      return std::optional<T>();
    }
    else
    {
       // Ensure that we are using a reasonable number of threads. Maximise the number of threads to the number of values.

      numberOfThreads = data.count() / 1000;

      if (numberOfThreads == 0)
      {
        numberOfThreads = 1;
      }
      else if (numberOfThreads > maxThreads)
      {
        numberOfThreads = maxThreads;
      }

      stepSize = data.size() / numberOfThreads;

      std::unique_ptr<T []> maxs(new T[numberOfThreads]);

        // Spawn the threads.

      for (threadNumber = 0; threadNumber < numberOfThreads; threadNumber++)
      {
        indexBegin = indexEnd;
        if (threadNumber == (numberOfThreads -1) )
        {
          indexEnd = data.size() -1;
        }
        else
        {
          indexEnd += stepSize;
        };
        thread = new boost::thread(&maxThread<T>, boost::cref(data), indexBegin, indexEnd, boost::ref(maxs[threadNumber]));
        threadGroup.add_thread(thread);
        thread = nullptr;
      };

      threadGroup.join_all();     // Wait for all the threads to finish.

      returnValue = maxs[0];

      for(index = 1; index < numberOfThreads; index++)
      {
        if (maxs[index] > returnValue)
        {
          returnValue = maxs[index];
        }
      }

      return std::optional<T>(returnValue);
    };
  }

  /// @brief Thread function to determine the minimum value in an array.
  /// @param[in]
  // 2013-08-02/GGB - Updated to use valarray const & and T for data.
  // 2012-11-30/GGB - Function created.

  template<typename T>
  void minThread(std::valarray<T> const &data, size_t indexStart, size_t indexEnd, T &min)
  {
    size_t index;

    min = data[indexStart++];

    for(index = indexStart; index < indexEnd; index++)
    {
      if (data[index] < min)
      {
        min = data[index];
      };
    };
  }

  /// @brief Function to determine the minimum value in an array.
  /// @param[in] data: The array to search.
  /// @version 2018-09-19/GGB - Use and return std::optional instead of boost::optional.
  /// @version 2013-08-02/GGB - Updated to use valarray const & and T for data.
  /// @version 2012-11-30/GGB - Function created.

  template<typename T>
  std::optional<T> min(std::valarray<T> const &data)
  {
    size_t numberOfThreads;
    size_t threadNumber;
    size_t stepSize;
    boost::thread_group threadGroup;
    boost::thread *thread;
    size_t indexBegin, indexEnd = 0;
    size_t index;
    T returnValue = 0;

    if (data.size() == 0)
    {
      return std::optional<T>();
    }
    else
    {
       // Ensure that we are using a reasonable number of threads. Maximise the number of threads to the number of values.

      numberOfThreads = data.size() / 1000;
      if (numberOfThreads == 0)
      {
        numberOfThreads = 1;
      }
      else if (numberOfThreads > maxThreads)
      {
        numberOfThreads = maxThreads;
      }

      stepSize = data.size() / numberOfThreads;

      std::unique_ptr<T []> mins(new T[numberOfThreads]);

        // Spawn the threads.

      for (threadNumber = 0; threadNumber < numberOfThreads; threadNumber++)
      {
        indexBegin = indexEnd;
        if (threadNumber == (numberOfThreads -1) )
        {
          indexEnd = data.size() -1;
        }
        else
        {
          indexEnd += stepSize;
        };
        thread = new boost::thread(&minThread<T>, boost::cref(data), indexBegin, indexEnd, boost::ref(mins[threadNumber]));
        threadGroup.add_thread(thread);
        thread = nullptr;
      };

      threadGroup.join_all();     // Wait for all the threads to finish.

      returnValue = mins[0];

      for(index = 1; index < numberOfThreads; index++)
      {
        if (mins[index] < returnValue)
        {
          returnValue = mins[index];
        };
      };

      return std::optional<T>(returnValue);
    };
  }

  /// @brief Thread function to determine the minimum and maximum value in an array.
  /// @param[in] data: The array to operate on.
  /// @param[in] indexStart: The array index this thread should start operating on.
  /// @param[in] indexEnd: The array index this thread should end on.
  /// @param[out] min: The minimum value found.
  /// @param[out] max: The maximum value found.
  /// @version 2013-08-02/GGB - 1) Converted to use type T for return values.<br>
  ///                           2) Changed parameter to const &
  /// @version 2013-03-11/GGB - Converted to use std::valarray<> as storage type.
  /// @version 2012-11-30/GGB - Function created.

  template<typename T>
  void minmaxThread(T *data, size_t indexStart, size_t indexEnd, T &min, T &max)
  {
    size_t index;

    max = min = data[indexStart];

    for(index = indexStart + 1; index < indexEnd; index++)
    {
      if (data[index] < min)
      {
        min = data[index];
      };

      if (data[index] > max)
      {
        max = data[index];
      };
    };
  }

  /// @brief Function to determine the minimum value in an array.
  /// @param[in] data: The data array
  /// @param[in] dataCount: The number of elements in the array.
  /// @returns The min and max value of the elements within the array.
  /// @throws None.
  /// @version 2018-09-19/GGB - Use and return std::optional instead of boost::optional.
  /// @version 2015-08-30/GGB - Function created.

  template<typename T>
  std::optional<std::tuple<T, T> > minmax(T *data, size_t dataCount)
  {
    size_t numberOfThreads;
    size_t threadNumber;
    size_t stepSize;
    boost::thread_group threadGroup;
    boost::thread *thread;
    size_t indexBegin, indexEnd = 0;
    size_t index;
    T max = 0;
    T min = 0;

    if (dataCount == 0)
    {
      return std::optional<std::tuple<T, T> >();
    }
    else
    {
       // Ensure that we are using a reasonable number of threads. Maximise the number of threads to the number of values.

      numberOfThreads = dataCount / 1000;

      if (numberOfThreads == 0)
      {
        numberOfThreads = 1;
      }
      else if (numberOfThreads > maxThreads)
      {
        numberOfThreads = maxThreads;
      };

      stepSize = dataCount / numberOfThreads;

      std::unique_ptr<T []> maxs(new T[numberOfThreads]);
      std::unique_ptr<T []> mins(new T[numberOfThreads]);

        // Spawn the threads.

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
        thread = new boost::thread(&minmaxThread<T>, boost::cref(data), indexBegin, indexEnd,
                                   boost::ref(mins[threadNumber]), boost::ref(maxs[threadNumber]));
        threadGroup.add_thread(thread);
        thread = nullptr;
      };

      threadGroup.join_all();     // Wait for all the threads to finish.

      min = mins[0];
      max = maxs[0];

      for(index = 1; index < numberOfThreads; index++)
      {
        if (mins[index] < min)
        {
          min = mins[index];
        };

        if (maxs[index] > max)
        {
          max = maxs[index];
        };
      };

      return std::optional<std::tuple<T, T> >(std::tuple<T, T>(min, max));
    };
  }
#endif // MCL_NOBOOST

}  // namespace MCL

#endif  // MCL_STATISTICS_MINMAX_HPP
