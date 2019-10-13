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
//                      Copyright 2015-2018 Gavin Blakeman.
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

#include "../include/angle.h"

  // MCL library header files.

#include "../include/constants.h"

  // Miscellaneous libraries

#include <GCL>

namespace MCL
{

  //********************************************************************************************************************************
  //
  // Friend Functions
  //
  //********************************************************************************************************************************

  /// @brief Stream insertion function for the class.
  /// @param[in] out: The output stream.
  /// @param[in] toOut: The point to send to the stream.
  /// @returns The output stream.
  /// @throws None.
  /// @version 2013-03-02/GGB - Function created.

  std::ostream &operator<<(std::ostream &out, CAngle const &toOut)
  {
    out << toOut.A2SD();

    return out;
  }

  /// @brief Returns the sine of an angle.
  /// @param[in] angle: The angle to take the sin of.
  /// @returns The sine of the angle.
  /// @throws None.
  /// @version 2017-09-23/GGB - Function created.

  FP_t sin(CAngle const &angle)
  {
    return (sin(angle.angle_));
  }

  /// @brief Returns the cosine of an angle.
  /// @param[in] angle: The angle to take the cos of.
  /// @returns The cosine of the angle.
  /// @throws None.
  /// @version 2017-09-23/GGB - Function created.

  FP_t cos(CAngle const &angle)
  {
    return (cos(angle.angle_));
  }

  /// @brief Returns the tangent of an angle.
  /// @param[in] angle - The angle to take the tangent of.
  /// @returns The tangent of the angle.
  /// @throws divide_by_zero()
  /// @version 2017-09-23/GGB - Function created.

  FP_t tan(CAngle const &angle)
  {
    if (angle.angle_ == 0)
    {
      throw divide_by_zero("Divide by zero in function MCL::tan(CAngle)");
    }
    else
    {
      return (tan(angle.angle_));
    };
  }

  //********************************************************************************************************************************
  //
  // Class CAngle
  //
  //********************************************************************************************************************************

  /// @brief The += operator for the class.
  /// @param[in] rhs - Right hand side argument.
  /// @returns Reference to this instance.
  /// @throws None.
  /// @version 2015-09-27/GGB - Function created.

  CAngle &CAngle::operator+=(CAngle const &rhs)
  {
    angle_ += rhs.angle_;

    return (*this);
  }

  /// @brief The -= operator for the class.
  /// @param[in] rhs - Right hand side argument.
  /// @returns Reference to this instance.
  /// @throws None.
  /// @version 2015-09-27/GGB - Function created.

  CAngle &CAngle::operator-=(CAngle const &rhs)
  {
    angle_ -= rhs.angle_;

    return (*this);
  }

  /// @brief Addition of two angles.
  /// @param[in] rhs - The value to add.
  /// @returns The angle added to the value of the RHS.
  /// @throws None
  /// @version 2016-03-25/GGB - Function created.

  const CAngle CAngle::operator+(CAngle const &rhs) const
  {
    CAngle returnValue(*this);

    returnValue += rhs;

    return returnValue;
  }

  /// @brief Multiplication by a double.
  /// @param[in] rhs - The value to multiply by.
  /// @returns The angle multiplied by the value of the RHS.
  /// @throws None
  /// @version 2016-03-25/GGB - Function created.

  CAngle &CAngle::operator*=(double const &rhs)
  {
    angle_ *= rhs;
    return *this;
  }

  /// @brief Multiplication by a double.
  /// @param[in] rhs - The value to multiply by.
  /// @returns The angle multiplied by the value of the RHS.
  /// @throws None
  /// @version 2016-03-25/GGB - Function created.

  const CAngle CAngle::operator*(double const &rhs) const
  {
    CAngle returnValue(*this);

    returnValue *= rhs;

    return returnValue;
  }

  /// @brief Converts the angle to a string of the form HH:mm:ss.ss"
  /// @returns A string representation of the angle.
  /// @throws None.
  /// @version 2017-09-24/GGB - Function created.

  std::string CAngle::A2SHMS() const
  {
    return GCL::sprintfHMS(hours());
  }

  /// @brief Converts the angle to a string of the form dd:mm:ss.ss"
  /// @returns A string representation of the angle.
  /// @throws None.
  /// @version 2017-09-24/GGB - Function created.

  std::string CAngle::A2SDMS() const
  {
    return GCL::sprintfDMS(degrees());
  }

  /// @brief Convert an angle in a specified format to radians.
  /// @param[in] value - The value to convert.
  /// @param[in] af - The format of the angle.
  /// @returns The angle in radians.
  /// @throws GCL::CError(MCL, 0x0100)
  /// @throws GCL::CCodeError(MCL)
  /// @version 2015-09-27/GGB - Function created.

  FP_t CAngle::convertToRadians(FP_t value, EAngleFormat af)
  {
    FP_t returnValue;

    switch (af)
    {
      case AF_NONE:
      {
        ERROR(MCL, 0x0100);
        break;
      };
      case AF_Dd:
      {
        returnValue = value * D_D2R;
        break;
      };
      case AF_DMSs:   // format = DDMMSS.ssssss
      {
        FP_t temp;

        value /= 10000;
        returnValue = std::floor(value);
        value -= returnValue;
        value *= 100;
        temp = std::floor(value);
        returnValue += temp / D_MPH;     // minutes
        value -= temp;
        value *= 100;
        temp = std::floor(value);
        returnValue += temp / D_SPH;   // seconds
        value -= temp;
        value /= D_SPH;
        returnValue += value;
        returnValue *= D_D2R;
        break;
      };
      case AF_HMSs:    // format = HHMMSS.ssssss
      {
        FP_t temp;

        value /= 10000;
        returnValue = std::floor(value);
        value -= returnValue;
        returnValue *= D_DPH;                 // Degrees
        value *= 100;
        temp = std::floor(value);
        returnValue += temp / D_MPH;             // minutes
        value -= temp;
        value *= 100;
        temp = std::floor(value);
        returnValue += temp / D_SPH;          // seconds
        value -= temp;
        value /= D_SPH;
        returnValue += value;
        returnValue *= D_D2R;
        break;
      };
      case AF_RADIANS:
      {
        returnValue = value;
        break;
      };
      default:
      {
        CODE_ERROR(MCL);
      };
    };

    return returnValue;
  }

  /// @brief Converts the angle value into an hh.hhh value.
  /// @returns angle converted to hh.hhhh
  /// @version 2018-05-12/GGB - Corrected error with conversion.

  FP_t CAngle::hours() const
  {
    FP_t returnValue = std::fabs(angle_ * D_R2D);
    FP_t hrsValue, fractionalPart;

    fractionalPart = std::modf(returnValue, &hrsValue);
    hrsValue /= D_DPH;

    returnValue = hrsValue + fractionalPart;

    return returnValue;
  }

}   // namespace MCL
