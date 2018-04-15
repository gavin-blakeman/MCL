//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								sort
// SUBSYSTEM:						Utility functions
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	boost
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2013-2016 Gavin Blakeman.
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
// OVERVIEW:            Implementation of templated and multi-threaded sort function.
//
// CLASSES INCLUDED:    None
//
// FUNCTIONS INCLUDED:  sort(...)
//
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-07-28 GGB - File Created.
//
//*********************************************************************************************************************************

#ifndef MCL_SORT_HPP
#define MCL_SORT_HPP

#include "../config.h"

  // Standard header files

#include <algorithm>
#include <valarray>

#ifndef MCL_NOBOOST
  // Boost Library

#ifndef MCL_NOMT
#include <boost/thread.hpp>
#endif // MCL_NOMT

#endif // MCL_NOBOOST

namespace MCL
{

  /// @brief Multi-threaded sorting algorithm.
  //
  /// @version 2013-09-22/GGB - Changed std::async to boost::thread.
  /// @version 2013-07-28/GGB - Function created.

  template<typename RAIter>
  void sort(RAIter begin, RAIter end)
  {
#ifdef MCL_NOMT
      // Devolve to using the std::sort algorthm.
    std::sort(begin, end);
#else // MCL_NOMT
    size_t len = std::distance(begin, end);
    size_t grainsize = std::max(size_t(256), len/maxThreads);

    if (len < grainsize)
    {
      std::sort(begin, end);
    }
    else
    {
      RAIter middle = begin;
      std::advance(middle, len/2);

      boost::thread thread = boost::thread(MCL::sort<RAIter>, begin, middle);
      MCL::sort(middle, end);
      thread.join();

      std::inplace_merge(begin, middle, end);
    };
#endif
  }

}

#endif // MCL_SORT_HPP
