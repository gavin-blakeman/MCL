//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								TVector3
// SUBSYSTEM:						3D vector template class
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None.
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
// OVERVIEW:            Implementation of a 3D templated point class.
//
// CLASSES INCLUDED:    TVector3D
//
// HISTORY:             2018-05-19/GGB - Changed class name to TVector3D.
//                      2015-09-22 GGB - astroManager 2015.09 release
//                      2012-12-26 GGB - File created.
//
//*********************************************************************************************************************************

#ifndef MCL_TVECTOR3_HPP
#define MCL_TVECTOR3_HPP

#include "MCLError.h"

namespace MCL
{
  template<typename T>
  class TVector3
  {
    template<typename U>
    friend TVector3<U> floor(TVector3<U> const &);

    template<typename U>
    friend TVector3<U> ceil(TVector3<U> const &);
  private:
    T value[3];

  protected:
  public:
    inline TVector3() { value[0] = value[1] = value[2] = 0; }
    inline TVector3(T const &v1, T const &v2, T const &v3) { value[0] = v1; value[1] = v2; value[2] = v3;}
    inline TVector3(TVector3 const &toCopy) { value[0] = toCopy.value[0]; value[1] = toCopy.value[1]; value[2] = toCopy.value[2]; }

    inline T const &x() const { return value[0];}
    inline T const &y() const { return value[1];}
    inline T const &z() const { return value[2];}

    inline T &x() { return value[0];}
    inline T &y() { return value[1];}
    inline T &z() { return value[2];}

    /// @brief Adds two vectors.
    /// @param[in] rhs - The vector to add to *this.
    /// @returns The sum of *this and rhs
    /// @version 2014-03-13/GGB - Function created.

    inline TVector3<T> operator +(TVector3<T> const &rhs) const
    {
      TVector3<T> result;

      result.value[0] = value[0] + rhs.value[0];
      result.value[1] = value[1] + rhs.value[1];
      result.value[2] = value[2] + rhs.value[2];

      return result;
    }

    /// Subtracts two vectors
    //
    // 2012-12-27/GGB - Function created.

    inline TVector3<T> operator -(TVector3<T> const &rhs) const
    {
      TVector3<T> result;

      result.value[0] = value[0] - rhs.value[0];
      result.value[1] = value[1] - rhs.value[1];
      result.value[2] = value[2] - rhs.value[2];

      return result;
    }

    /// Multiply the point (vector) by a constant value.
    //
    // 2012-12-27/GGB - Function created.

    template<typename U>
    inline TVector3 &operator *= (U mult)
    {
      value[0] *= mult;
      value[1] *= mult;
      value[2] *= mult;

      return *this;
    }

    /// Less than equal to operator
    //
    // 2013-01-10/GGB - Function created.

    inline bool operator <= (TVector3<T> const &rhs) const
    {
      return (square(value[0]) + square(value[1]) + square(value[2])) < (square(rhs.value[0]) + square(rhs.value[1]) + square(rhs.value[2]));
    }

    /// @brief Returns the vector coordinate at the relevant position.
    /// @param[in] index - The index to get the value of
    /// @returns Reference to the vector position.
    /// @throws 0x2000 - TVector3: operator [] index out range [0, 2].
    /// @version 2012-12-28/GGB - Function created.

    inline T &operator[](int index)
    {
      if ( (index < 0) || (index > 2) )
      {
        MCL_ERROR(0x2000);    // TVector3: operator [] index out range [0, 2].
      }
      else
      {
        return value[index];
      };
    }

    /// @brief Returns the vector coordinate at the relevant position.
    /// @throws 0x2000 - TVector3: operator [] index out range [0, 2].
    //
    // 2013-01-13/GGB - Function created.

    inline T const &operator[](int index) const
    {
      if ( (index < 0) || (index > 2) )
      {
        MCL_ERROR(0x2000);    // TVector3: operator [] index out range [0, 2].
      }
      else
      {
        return value[index];
      };
    }

    /// Returns the dot product of two 3D vectors.
    //
    // 2012-12-27/GGB - Function created.

    template<typename U>
    inline FP_t dot(TVector3<U> const &rhs) const
    {
      return (value[0] * rhs.value[0] + value[1] * rhs.value[1] + value[2] * rhs.value[2]);
    }

    /// @brief Determines the normal (unit vector) of the vector.
    /// @details - Normalises the length of the vector to 1. (unit vector)
    /// @returns - The normalised vector.
    /// @throws None.
    /// @version 2012-12-28/GGB - Function created.

    inline TVector3 normalise() const
    {
      TVector3<T> result;

      FP_t invlen = 1.0 / sqrt(pow2(value[0]) + pow2(value[1]) + pow2(value[2]) );
      result.value[0] = value[0] * invlen;
      result.value[1] = value[1] * invlen;
      result.value[2] = value[2] * invlen;

      return result;
    }


    /// @brief Returns the cross product of two 3D vectors.
    /// @param[in] rhs = The vector to cross product with this vector.
    /// @returns
    //
    // 2012-12-27/GGB - Function created.

    inline TVector3<T> cross(TVector3<T> rhs) const
    {
      TVector3<T> result;

      result.value[0] = value[1] * rhs.value[2] - value[2] - rhs.value[1];
      result.value[1] = value[2] * rhs.value[0] - value[0] * rhs.value[2];
      result.value[2] = value[0] * rhs.value[1] - value[1] * rhs.value[0];

      return result;
    }

  };  // class TVector3

  /// @brief Function to determine the ceil() of a vector.
  /// @param[in] val - The vector to determine the ceiling of.
  /// @returns The vector ceiling.
  /// @version 2013-01-13/GGB - Function created.

  template<typename U>
  TVector3<U> ceil(TVector3<U> const &val)
  {
    MCL::TVector3<U> returnValue;

    returnValue.x() = ceil(val.x());
    returnValue.y() = ceil(val.y());
    returnValue.z() = ceil(val.z());

    return returnValue;
  }

  /// Function to determine the floor of a vector.
  //
  // 2013-01-13/GGB - Function created.

  template<typename U>
  TVector3<U> floor(TVector3<U> const &val)
  {
    MCL::TVector3<U> returnValue;

    returnValue.x() = floor(val.x());
    returnValue.y() = floor(val.y());
    returnValue.z() = floor(val.z());

    return returnValue;
  }

}  // namespace MCL

#endif // MCL_TVECTOR3_HPP
