//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								TPoint2D.hpp
// SUBSYSTEM:						Point template class.
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.(GGB)
// LICENSE:             GPLv2
//
//                      Copyright 2011-2017 Gavin Blakeman.
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
// HISTORY:             2015-09-22 GGB - AIRDAS 2015.09 release
//                      2013-09-30 GGB - AIRDAS 2013.09 release.
//                      2013-06-08 GGB - Replaced typecast long and typecast double with a templated function.
//                      2013-03-22 GGB - AIRDAS 2013.03 release.
//                      2013-01-20 GGB - AIRDAS 0000.00 release.
//                      2011-08-27 GGB - Development of class for openAIRS application.
//
//*********************************************************************************************************************************

#ifndef MCL_TPOINT_H
#define MCL_TPOINT_H

#include "MCLError.h"

namespace MCL
{
  template<typename T>
  class TPoint2D
  {
  private:
    T xVal;
    T yVal;

  protected:
  public:
    inline TPoint2D() : xVal(0), yVal(0) {;}
    inline TPoint2D(T const &newX, T const &newY) : xVal(newX), yVal(newY) {;}
    inline TPoint2D(TPoint2D const &toCopy) : xVal(toCopy.xVal), yVal(toCopy.yVal) {;}

    bool operator==(TPoint2D const &rhs) const { return ((xVal == rhs.xVal) && (yVal == rhs.yVal)); }

    virtual TPoint2D &operator-=(TPoint2D const &);

    TPoint2D<T> operator*=(double const &);
    TPoint2D<T> operator*(double const &) const;

    /// @brief Division operator
    /// @param[in] divisor - The divisor to apply.
    /// @returns The point divided by the divisor.
    /// @version 2011-08-28/GGB - Function created

    template<typename U>
    TPoint2D operator /(U divisor)
    {
      TPoint2D<T> retVal;

      if (divisor == 0)
      {
        MCL_ERROR(0x1000);
      }
      else
      {
        retVal.xVal = (T) (static_cast<double>(xVal) / static_cast<double>(divisor));
        retVal.yVal = (T) (static_cast<double>(yVal) / static_cast<double>(divisor));
      };

      return retVal;
    }

    TPoint2D &operator=(TPoint2D const &);
    virtual TPoint2D operator-(const TPoint2D &);

    /// Typecase operator
    //
    // 2013-06-08/GGB - Function created.

    template<typename U>
    operator TPoint2D<U>() const
    {
      TPoint2D<U> returnValue;

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

    inline TPoint2D &set(T _x, T _y) { xVal = _x; yVal = _y; return *this;}

    template<typename U>
    inline friend std::ostream &operator<<(std::ostream &, TPoint2D<U> const &);

    /// @brief Operator() for assigning values.
    /// @param[in] x - x-value
    /// @param[in] y - y-value
    /// @throws None.
    /// @version 2017-09-23/GGB - Function created.

    void operator()(T const &x, T const &y)
    {
      xVal = x;
      yVal = y;
    }
  };

  // Subtraction operator.
  //
  // 2011-08-28/GGB - Function created

  template<typename T>
  TPoint2D<T> TPoint2D<T>::operator-(const TPoint2D<T> &rhs)
  {
    return TPoint2D<T>(*this) -= rhs;
  }

  // -= operator
  //
  // 2011-08-28/GGB - Function created.

  template<typename T>
  TPoint2D<T> &TPoint2D<T>::operator-=(const TPoint2D<T> &rhs)
  {
    if (this == &rhs)
    {
        // Self assignement. Makes all values equal to zero.

      xVal = yVal = 0;
    }
    else
    {
      xVal -= rhs.xVal;
      yVal -= rhs.yVal;
    };

    return (*this);
  }

  /// Copy operator for class.
  //
  // 2012-01-13/GGB - Function created

  template<typename T>
  TPoint2D<T> &TPoint2D<T>::operator=(TPoint2D<T> const &rhs)
  {
    if ( this != &rhs )
    {
      xVal = rhs.xVal;
      yVal = rhs.yVal;
    };

    return *this;
  }

  /// @brief Stream insertion function for the class.
  /// @param[in] out - The output stream.
  /// @param[in] toOut - The point to send to the stream.
  /// @returns The output stream.
  /// @throws None.
  /// @version 2013-03-02/GGB - Function created.

  template<typename T>
  std::ostream &operator<<(std::ostream &out, TPoint2D<T> const &toOut)
  {
    //out << "x: ";// << toOut.xVal << " y: " << toOut.yVal;

    //out << toOut.xVal;

    return out;
  }

  /// Friend multiplication function.
  //
  // 2014-03-07/GGB - Function created.

  template<typename T>
  TPoint2D<T> TPoint2D<T>::operator*= (double const &rhs)
  {
    xVal *= rhs;
    yVal *= rhs;

    return (*this);
  }

  /// Friend multiplication function.
  //
  // 2014-03-07/GGB - Function created.

  template<typename T>
  TPoint2D<T> TPoint2D<T>::operator* (double const &rhs) const
  {
    return TPoint2D<T>(*this) *= rhs;
  }

}  // namespace MCL

#endif // MCL_TPOINT_H
