//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								TVector3D
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

#ifndef MCL_TVECTOR3D_HPP
#define MCL_TVECTOR3D_HPP

#include "MCLError.h"

namespace MCL
{
  template<typename T>
  class TVector3D
  {
    template<typename U>
    friend TVector3D<U> floor(TVector3D<U> const &);

    template<typename U>
    friend TVector3D<U> ceil(TVector3D<U> const &);
  private:
    T value[3];

  protected:
  public:
    inline TVector3D() { value[0] = value[1] = value[2] = 0; }
    inline TVector3D(T const &v1, T const &v2, T const &v3) { value[0] = v1; value[1] = v2; value[2] = v3;}
    inline TVector3D(TVector3D const &toCopy) { value[0] = toCopy.value[0]; value[1] = toCopy.value[1]; value[2] = toCopy.value[2]; }

    inline T const &x() const { return value[0];}
    inline T const &y() const { return value[1];}
    inline T const &z() const { return value[2];}

    inline T &x() { return value[0];}
    inline T &y() { return value[1];}
    inline T &z() { return value[2];}

    /// @brief Adds two vectors.
    /// @param[in] rhs: The vector to add to *this.
    /// @returns The sum of *this and rhs
    /// @version 2014-03-13/GGB - Function created.

    inline TVector3D<T> operator +(TVector3D<T> const &rhs) const
    {
      TVector3D<T> result;

      result.value[0] = value[0] + rhs.value[0];
      result.value[1] = value[1] + rhs.value[1];
      result.value[2] = value[2] + rhs.value[2];

      return result;
    }

    /// @brief Subtracts two vectors
    /// @param[in] rhs: The vector to subtract from *this.
    /// @returns The result of the subtraction.
    /// @version 2012-12-27/GGB - Function created.

    inline TVector3D<T> operator -(TVector3D<T> const &rhs) const
    {
      TVector3D<T> result;

      result.value[0] = value[0] - rhs.value[0];
      result.value[1] = value[1] - rhs.value[1];
      result.value[2] = value[2] - rhs.value[2];

      return result;
    }

    /// @brief Multiply the point (vector) by a constant value.
    /// @param[in] mult: Value to multiply.
    /// @returns The vector multiplied by the constant value.
    /// @version 2012-12-27/GGB - Function created.

    template<typename U>
    inline TVector3D &operator *= (U mult)
    {
      value[0] *= mult;
      value[1] *= mult;
      value[2] *= mult;

      return *this;
    }

    /// Less than equal to operator
    //
    // 2013-01-10/GGB - Function created.

    inline bool operator <= (TVector3D<T> const &rhs) const
    {
      return (square(value[0]) + square(value[1]) + square(value[2])) < (square(rhs.value[0]) + square(rhs.value[1]) + square(rhs.value[2]));
    }

    /// @brief Returns the vector coordinate at the relevant position.
    /// @param[in] index: The index to get the value of
    /// @returns Reference to the vector position.
    /// @throws std::out_of_range
    /// @version 2012-12-28/GGB - Function created.

    inline T &operator[](int index)
    {
      if ( (index < 0) || (index > 2) )
      {
        throw std::out_of_range("Index out of Range. [0; 2]");
      }
      else
      {
        return value[index];
      };
    }

    /// @brief Returns the vector coordinate at the relevant position.
    /// @param[in] index: The index to get the value of
    /// @returns Reference to the value at position.
    /// @throws std::out_of_range
    /// @version 2013-01-13/GGB - Function created.

    inline T const &operator[](int index) const
    {
      if ( (index < 0) || (index > 2) )
      {
        throw std::out_of_range("Index out of Range. [0; 2]");
      }
      else
      {
        return value[index];
      };
    }

    /// @brief Returns the dot product of two 3D vectors.
    /// @param[in] rhs: The vector to dot with this.
    /// @returns The dot product of the two vectors.
    /// @version 2012-12-27/GGB - Function created.

    template<typename U>
    inline FP_t dot(TVector3D<U> const &rhs) const
    {
      return (value[0] * rhs.value[0] + value[1] * rhs.value[1] + value[2] * rhs.value[2]);
    }

    /// @brief Determines the normal (unit vector) of the vector.
    /// @details - Normalises the length of the vector to 1. (unit vector)
    /// @returns - The normalised vector.
    /// @throws None.
    /// @version 2012-12-28/GGB - Function created.

    inline TVector3D normalise() const
    {
      TVector3D<T> result;

      FP_t invlen = 1.0 / std::sqrt(MCL::pow2(value[0]) + MCL::pow2(value[1]) + MCL::pow2(value[2]) );
      result.value[0] = value[0] * invlen;
      result.value[1] = value[1] * invlen;
      result.value[2] = value[2] * invlen;

      return result;
    }

    /// @brief Returns the cross product of two 3D vectors.
    /// @param[in] rhs: The vector to cross product with this vector.
    /// @returns The cross product of the vectors.
    /// @throws None.
    /// @version 2012-12-27/GGB - Function created.

    inline TVector3D<T> cross(TVector3D<T> rhs) const noexcept
    {
      TVector3D<T> result;

      result.value[0] = value[1] * rhs.value[2] - value[2] - rhs.value[1];
      result.value[1] = value[2] * rhs.value[0] - value[0] * rhs.value[2];
      result.value[2] = value[0] * rhs.value[1] - value[1] * rhs.value[0];

      return result;
    }

    /// @brief Returns the length of a vector.
    /// @returns The length of the specified vector.
    /// @throws None.
    /// @version 2018-05-20/GGB - Function created.

    FP_t length() const noexcept
    {
      return sqrt(pow2(value[0]) + pow2(value[1]) + pow2(value[2]) );
    }

  };  // class TVector3

  /// @brief Function to determine the ceil() of a vector.
  /// @param[in] val - The vector to determine the ceiling of.
  /// @returns The vector ceiling.
  /// @throws None.
  /// @version 2013-01-13/GGB - Function created.

  template<typename U>
  TVector3D<U> ceil(TVector3D<U> const &val)
  {
    MCL::TVector3D<U> returnValue;

    returnValue.x() = ceil(val.x());
    returnValue.y() = ceil(val.y());
    returnValue.z() = ceil(val.z());

    return returnValue;
  }

  /// Function to determine the floor of a vector.
  //
  // 2013-01-13/GGB - Function created.

  template<typename U>
  TVector3D<U> floor(TVector3D<U> const &val)
  {
    MCL::TVector3D<U> returnValue;

    returnValue.x() = floor(val.x());
    returnValue.y() = floor(val.y());
    returnValue.z() = floor(val.z());

    return returnValue;
  }

}  // namespace MCL

#endif // MCL_TVECTOR3D_HPP
