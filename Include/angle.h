//*********************************************************************************************************************************
//
// PROJECT:							Maths Class Library
// FILE:								angle
// SUBSYSTEM:						Angle class
// LANGUAGE:						C++
// TARGET OS:						None.
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman (GGB)
// LICENSE:             GPLv2
//
//                      Copyright 2015-2017 Gavin Blakeman.
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
// OVERVIEW:						An angle class to handle printing and conversion from different formats.
//
// CLASSES INCLUDED:		CAngle
//
// CLASS HIERARCHY:     CAngle
//
// HISTORY:             2015-09-27 GGB - File Created
//
//*********************************************************************************************************************************

#ifndef MCL_ANGLE_H
#define MCL_ANGLE_H

  // MCL Library

#include "config.h"
#include "constants.h"

  // Standard C++ libraries

#include <string>

namespace MCL
{
  /// @brief Different coordinate formats that are recognised by the software.
  /// These formats are used to enable automatic conversion of coordinates when creating certain data structures.
  /// Internally, all coordinates are stored as radians.

  enum EAngleFormat
  {
    AF_NONE,
    AF_Dd,        ///< format = D.dddd
    AF_DMSs,      ///< format = DDMMSS.ssssss
    AF_HMSs,      ///< format = HHMMSS.ssssss
    AF_RADIANS    ///< format = R.rrrrr
  };

  class CAngle
  {
  private:
    FP_t angle_;      ///< Angle. Always stored as radians.

    CAngle() = delete;

  protected:
    static FP_t convertToRadians(FP_t, EAngleFormat);

  public:
    CAngle(FP_t na, EAngleFormat af = AF_RADIANS) : angle_(convertToRadians(na, af)) {}
    CAngle(CAngle const &toCopy) : angle_(toCopy.angle_) {}

      // Mathmatical operators

    virtual CAngle &operator+=(CAngle const &);
    virtual CAngle &operator-=(CAngle const &);
    virtual const CAngle operator+(CAngle const &) const;
    virtual CAngle &operator*=(double const &);
    virtual const CAngle operator*(double const &) const;

      // Conversion functions

    virtual FP_t degrees() const { return angle_ * K_R2D; }
    virtual FP_t hours() const;
    virtual FP_t radians() const { return angle_; }

      // Stringification functions

    virtual std::string A2SD() const {}
    virtual std::string A2SHMS() const;
    virtual std::string A2SDMS() const;

    friend std::ostream &operator<<(std::ostream &out, CAngle const &toOut);
    friend FP_t sin(CAngle const &);
    friend FP_t cos(CAngle const &);
    friend FP_t tan(CAngle const &);
  };

  typedef CAngle angle_t;

}   // namespace MCL

#endif // MCL_ANGLE_HPP
