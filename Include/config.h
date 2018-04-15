//*************************************************************************************************
//
// PROJECT:							MCL (Math Class Library)
// FILE:								shared.h
// SUBSYSTEM:						shared definitions.
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2010-2016 Gavin Blakeman.
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
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//
//*************************************************************************************************

#ifndef MCL_CONFIG_H
#define MCL_CONFIG_H

#ifdef EMBEDDED
  #ifdef __XC32
    #define MCL_NOBOOST
    #define MCL_NOMT
    #define MCL_REALTIME
    #define MCL_NOSTRINGS
    #define MCL_CONTROL
  #endif  // __XC32
#else   // EMBEDDED
  #undef MCL_NOBOOST
  #undef MCL_NOMT
  #undef MCL_REALTIME
  #undef MCL_NOSTRINGS
  #undef MCL_CONTROL
#endif  // EMBEDDED

#include <cstddef>

namespace MCL
{
#ifndef MCL_NOMT
  extern size_t maxThreads;
#endif // MCL_NOMT

#ifdef MCL_FPT_SINGLE
  typedef float FP_t;
#else
  typedef double FP_t;
#endif

}

#endif // MCL_CONFIG_H
