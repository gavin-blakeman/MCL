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
// CLASSES INCLUDED:    None
//
// HISTORY:             2018-09-20 GGB - Changed to generic format used by GCL.
//                      2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-03-22 GGB - astroManager 2013.03 release
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-07-10 GGB - Development of class for openAIRS application.
//
//*********************************************************************************************************************************

#include "../include/error.h"

namespace MCL
{
  class CLoader
  {
  private:
    void loadErrorMessages();
  public:
    CLoader();
  };

  static CLoader executeLoader;

  CLoader::CLoader()
  {
    loadErrorMessages();
  }

  /// @brief Adds the ACL library error codes into the GCL error object.
  /// @throws None.
  /// @version  2015-07-28/GGB - Function created.

  void CLoader::loadErrorMessages()
  {
    std::vector<std::pair<GCL::TErrorCode, std::string>> errors =
    {
      {0x1000, std::string("NUMERIC: Value out of range.")},
      {0x2000, std::string("TVector3: operator [] index out range [0, 2].")},
      {0x0100, std::string("CAngle: AF_NONE not allowed.")}
    };

    std::for_each(errors.begin(), errors.end(),
                  [] (std::pair<GCL::TErrorCode, std::string> p) { GCL::CError::addErrorMessage("MCL", p.first, p.second); });

  }

}  // namespace MCL
