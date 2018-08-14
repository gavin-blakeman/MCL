//*********************************************************************************************************************************
//
// PROJECT:							Maths Class Library
// FILE:								common
// SUBSYSTEM:						Common definitions
// LANGUAGE:						C++
// TARGET OS:						None.
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman (GGB)
// LICENSE:             GPLv2
//
//                      Copyright 2015-2016 Gavin Blakeman.
//                      This file is part of the Maths Class Library (MCL)
//
//                      MCL is free software: you can redistribute it and/or modify it under the terms of the GNU General
//                      Public License as published by the Free Software Foundation, either version 2 of the License, or
//                      (at your option) any later version.
//
//                      MCL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
//                      implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
//                      for more details.
//
//                      You should have received a copy of the GNU General Public License along with MCL.  If not,
//                      see <http://www.gnu.org/licenses/>.
//
//
// OVERVIEW:						Common definitions that can be used by multiple files
//
//
// CLASSES INCLUDED:		None
//
// CLASS HIERARCHY:     None.
//
// FUNCTIONS INCLUDED:  std::string getVersionString()
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2015-06-29 GGB - File created.
//
//*********************************************************************************************************************************

#include "../Include/common.h"

  // Standard libraries

#include <iomanip>
#include <sstream>
#include <string>

  // Boost Library

#include <boost/algorithm/string.hpp>

namespace MCL
{

  unsigned int const MCL_MAJORVERSION = 2018;           ///< The Major version number (yyyy)
  unsigned int const MCL_MINORVERSION = 9;              ///< The Minor version number (mm)
  unsigned int const MCL_BUILDNUMBER  = 0x0051;         ///< The build numnber - incremented on each build.

  /// @brief Returns the library version and build number.
  /// that was used for editing the library.
  /// @returns A string with the application name, version, build.
  /// @throws Nothing.
  //
  // 2015-06-29/GGB - Function created.

  std::string getVersionString()
  {
    std::stringstream s;

    s << MCL_MAJORVERSION << "." << std::setfill('0') << std::setw(2) << MCL_MINORVERSION << std::setw(4) << std::hex << MCL_BUILDNUMBER << std::endl;

    std::string returnValue = s.str();
    boost::algorithm::to_upper(returnValue);

    return returnValue;
  }
}
