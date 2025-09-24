//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								point2D.hpp
// SUBSYSTEM:						Point template class.
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.(GGB)
// LICENSE:             GPLv2
//
//                      Copyright 2011-2025 Gavin Blakeman.
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
// OVERVIEW:            Implementation of a templated poihnt class.
//
// CLASSES INCLUDED:    TPoint2D
//
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2013-09-30 GGB - astroManager 2013.09 release.
//                      2013-06-08 GGB - Replaced typecast long and typecast double with a templated function.
//                      2013-03-22 GGB - astroManager 2013.03 release.
//                      2013-01-20 GGB - astroManager 0000.00 release.
//                      2011-08-27 GGB - Development of class for openAIRS application.
//
//*********************************************************************************************************************************

#ifndef MCL_POINT2D_H
#define MCL_POINT2D_H

#ifndef __EMBEDDED__
#include "exceptions.h"
#include <GCL>
#endif

namespace MCL
{
  template<typename T>
  class point2D
  {
  public:
    inline point2D() = default;
    inline point2D(point2D const &) = default;
    inline point2D(point2D &&) = default;
    inline point2D(T const &newX, T const &newY) : xVal(newX), yVal(newY) {}

    inline point2D &operator=(point2D const &) = default;
    inline point2D &operator=(point2D &&) = default;

    inline T X() const noexcept { return xVal; }
    inline T &X() noexcept { return xVal; }
    inline T Y() const noexcept { return yVal; }
    inline T &Y() noexcept { return yVal; }


    bool operator==(point2D const &rhs) const { return ((xVal == rhs.xVal) && (yVal == rhs.yVal)); }

    /// @brief Unitary negative operator
    /// @returns An instance containing the negative of the point. (-x, -y)
    /// @throws

    point2D operator-() const
    {
      return TPoint2D(-xVal, -yVal);
    }

    point2D &operator-=(point2D const &);

    point2D<T> operator*=(double const &);
    point2D<T> operator*(double const &) const;

    /// @brief Division operator
    /// @param[in] divisor: The divisor to apply.
    /// @returns The point divided by the divisor.

    template<typename U>
    point2D operator /(U divisor)
    {
      point2D<T> retVal;

      if (divisor == 0)
      {
#ifndef __EMBEDDED__
        ERRORMESSAGE("NUMERIC: Value out of range.");
#endif
      }
      else
      {
        retVal.xVal = (T) (static_cast<double>(xVal) / static_cast<double>(divisor));
        retVal.yVal = (T) (static_cast<double>(yVal) / static_cast<double>(divisor));
      };

      return retVal;
    }

    virtual point2D operator-(const point2D &);

    /// @brief Typecast operator
    /// @returns The value typecast to the new type.
    /// @throws None.

    template<typename U>
    operator point2D<U>() const
    {
      point2D<U> returnValue;

      returnValue.x() = (U) xVal;
      returnValue.y() = (U) yVal;

      return returnValue;
    }

    inline void x(T nv) { xVal = nv; }
    inline void y(T nv) { yVal = nv; }

    inline T const &x() const { return xVal;}
    inline T const &y() const { return yVal;}

    inline T &x() { return xVal;}
    inline T &y() { return yVal;}

    inline point2D &set(T _x, T _y) { xVal = _x; yVal = _y; return *this;}

#ifndef __EMBEDDED__
    template<typename U>
    inline friend std::ostream &operator<<(std::ostream &, point2D<U> const &);

#endif

    /// @brief Operator() for assigning values.
    /// @param[in] x: x-value
    /// @param[in] y: y-value
    /// @throws None.
    /// @version 2017-09-23/GGB - Function created.

    void operator()(T const &x, T const &y)
    {
      xVal = x;
      yVal = y;
    }

    /// @brief Addition assignment operator with a constant value. Constant value gets added to both members.
    /// @param[in] rhs: The value to add to the members.
    /// @throws None.

    template<typename U>
    point2D &operator +=(U rhs)
    {
      xVal += static_cast<T>(rhs);
      yVal += static_cast<T>(rhs);

      return *this;
    }

    /// @brief Addition operator with a constant value. Constant value gets added to both members.
    /// @param[in] rhs: The value to add to the members.
    /// @throws None.
    /// @version 2020-03-01/GGB - Function created.

    template<typename U>
    point2D operator+(U rhs)
    {
      point2D temp = *this;
      temp += rhs;
      return temp;
    }

  private:
    T xVal;
    T yVal;

  };  // class TPoint2D.


  /// @brief Subtraction operator.
  /// @param[in] rhs: The right hand value to add.
  /// @returns Object representing the added values.
  /// @throws None.
  /// @version 2011-08-28/GGB - Function created

  template<typename T>
  point2D<T> point2D<T>::operator-(const point2D<T> &rhs)
  {
    return point2D<T>(*this) -= rhs;
  }

  // -= operator
  //
  // 2011-08-28/GGB - Function created.

  template<typename T>
  point2D<T> &point2D<T>::operator-=(const point2D<T> &rhs)
  {
    if (this == &rhs)
    {
      // Self assignment. Makes all values equal to zero.

      xVal = yVal = 0;
    }
    else
    {
      xVal -= rhs.xVal;
      yVal -= rhs.yVal;
    };

    return (*this);
  }

  /// @brief Stream insertion function for the class.
  /// @param[in] out: The output stream.
  /// @param[in] toOut: The point to send to the stream.
  /// @returns The output stream.
  /// @throws None.

#ifndef __EMBEDDED__

  template<typename T>
  std::ostream &operator<<(std::ostream &out, point2D<T> const &toOut)
  {
    //out << "x: ";// << toOut.xVal << " y: " << toOut.yVal;

    //out << toOut.xVal;

    return out;
  }

#endif

  /// @brief Friend multiplication function.
  /// @param[in] rhs: The right hand value.
  /// @version 2014-03-07/GGB - Function created.

  template<typename T>
  point2D<T> point2D<T>::operator*= (double const &rhs)
  {
    xVal *= rhs;
    yVal *= rhs;

    return (*this);
  }

  /// @brief Friend multiplication function.
  /// @param[in] rhs: The value to multiply by.
  /// @throws None.
  /// @version 2014-03-07/GGB - Function created.

  template<typename T>
  point2D<T> point2D<T>::operator* (double const &rhs) const
  {
    return point2D<T>(*this) *= rhs;
  }

}  // namespace MCL

#endif // MCL_TPOINT_H
