//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								MCLError.h
// SUBSYSTEM:						Mathematical Class Library Errors
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	GCL
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2011-2016 Gavin Blakeman.
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
//                      2013-03-22 GGB - astroManager 2013.03 release
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-07-10 GGB - Development of class for openAIRS application.
//
//*********************************************************************************************************************************

#include "../Include/MCLError.h"

#include "boost/lexical_cast.hpp"

#include <GCL>

namespace MCL
{
  TErrorStore CMCLError::errorMessages;

  struct SErrorCodes
  {
    size_t errorCode;
    std::string errorMessage;
  };

  SErrorCodes errorArray[] =
  {
    {0x1000, std::string("NUMERIC: Value out of range.")},
    {0x2000, std::string("TVector3: operator [] index out range [0, 2].")},
    {0x0100, std::string("CAngle: AF_NONE not allowed.")}
  };

  /// Returns the string of the error message.
  //
  // 2011-03-13/GGB - Function created.

  std::string CMCLError::errorMessage() const
  {
    TErrorStore:: const_iterator errorData;

    if ((errorData = errorMessages.find(errorCode_)) == errorMessages.end() )
    {
        // Error message not found - Error code has not been defined.
        // This is a non-recoverable error.

      exit(0xFFFE);		// Non-recoverable error within an error
    }
    else
      return (errorData->second);
  }

  /// Static function to copy all the error messages from the array into the map.
  /// The error messages do not have to be in order or contiguous in the array.
  //
  // 2011-03-13/GGB - Function created.

  void CMCLError::loadErrorMessages()
  {
    size_t elements = sizeof(errorArray) / sizeof(SErrorCodes);   // Work out how many elements stored.
    size_t index;

    for (index = 0; index < elements; index++)
      errorMessages[errorArray[index].errorCode] = errorArray[index].errorMessage;
  }

  /// Function to write the error message to a logFile.
  /// This is not automatically done in the library when an exception is thrown as the library may be able to recover from the
  /// exception without having to terminate.
  //
  // 2014-12-24/GGB - Function created.

  void CMCLError::logErrorMessage() const
  {
    TErrorStore::const_iterator errorData;

    if ((errorData = errorMessages.find(errorCode_)) == errorMessages.end() )
    {
        // Error message not found - Error code has not been defined.
        // This is a non-recoverable error.

      GCL::logger::defaultLogger().logMessage(GCL::logger::error,
                                           "Non recoverable error within an error in MCL. Error Code: " +
                                           boost::lexical_cast<std::string>(errorCode_) + ". Terminating");
      exit(0xFFFE);		// Non-recoverable error within an error
    }
    else
      GCL::logger::defaultLogger().logMessage(GCL::logger::warning,
                                           "Error Code: " + boost::lexical_cast<std::string>(errorData->first) +
                                           " - " + errorData->second);
  }

  //********************************************************************************************************************************
  //
  // CMCLCodeError
  //
  //********************************************************************************************************************************

  /// Creates a string for the error message.
  //
  // 2013-03-23/GGB - Changed to use streams.
  // 2011-02-26/GGB - Function created.

  std::string CMCLCodeError::errorMessage() const
  {
    std::ostringstream o;

    o << "A code error has occurred in the libAstroClass Library." << std::endl;
    o << "File name: " << fileName << " dated: " << timeStamp << std::endl;
    o << "Line number: " << lineNo << std::endl;

    return o.str();
  }

  /// Function to write the error message to a logFile.
  /// This is not automatically done in the library when an exception is thrown as the library may be able to recover from the
  /// exception without having to terminate.
  //
  // 2014-12-24/GGB - Function created.

  void CMCLCodeError::logErrorMessage() const
  {
    GCL::logger::defaultLogger().logMessage(GCL::logger::error,
                                         "A Code Error has occurred in the MCL library File Name: " + fileName +
                                         ". Line Number: " + boost::lexical_cast<std::string>(lineNo));
  }

}  // namespace MCL
