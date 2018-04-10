//*********************************************************************************************************************************
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
// OVERVIEW:
//
// HISTORY:             2015-09-22 GGB - AIRDAS 2015.09 release
//
//*********************************************************************************************************************************

#include "../Include/config.h"

#include <thread>

namespace MCL
{
  size_t maxThreads = std::thread::hardware_concurrency();      // Default number of threads used for the multi-threaded functions.
}
