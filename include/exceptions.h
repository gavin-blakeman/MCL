﻿//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								MCLError.h
// SUBSYSTEM:						Mathematical Class Library Errors
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	GCL
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman (GGB)
// LICENSE:             GPLv2
//
//                      Copyright 2011-2018 Gavin Blakeman.
//                      This file is part of the Math Class Library (MCL)
//
//                      MCL is free software: you can redistribute it and/or modify it under the terms of the GNU General
//                      Public License as published by the Free Software Foundation, either version 2 of the License, or
//                      (at your option) any later version.
//
//                      MCL  is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
//                      implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
//                      for more details.
//
//                      You should have received a copy of the GNU General Public License along with MCL.  If not,
//                      see <http://www.gnu.org/licenses/>.
//
// OVERVIEW:            This file implements exceptions that are used for error reporting by the MCL library.
//
// CLASSES INCLUDED:    CMCLError
//                      CMCLCodeError
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-03-22 GGB - astroManager 2013.03 release.
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-07-10 GGB - Development of class for openAIRS application.
//
//*********************************************************************************************************************************

#ifndef MCL_MCLERROR_H
#define MCL_MCLERROR_H

  // Standard C++ libraries

#include <stdexcept>
#include <string>

  // Miscellaneous libraries

//#include "../GCL/include/error.h" //!!! If the full GCL package is included at this point, it creates cicular references and errors.

namespace MCL
{
  class divide_by_zero : public std::runtime_error
  {
  private:
    divide_by_zero() = delete;
  public:
    divide_by_zero(std::string const &arg) : std::runtime_error(arg) {}
    divide_by_zero(divide_by_zero const &) = default;
    virtual ~divide_by_zero() = default;
  };

}	// namespace MCL

#endif // MCL_MCLERROR_H
