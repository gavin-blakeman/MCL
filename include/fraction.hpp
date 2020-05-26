//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								fraction.hpp
// SUBSYSTEM:						Fractional class
// LANGUAGE:						C++
// TARGET OS:						None.
// LIBRARY DEPENDANCE:	None.
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2020 Gavin Blakeman.
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
// OVERVIEW:            Implementation of a fraction class.
//
// CLASSES INCLUDED:    None
//
//
// HISTORY:             2020-04-24 GGB - File Created
//
//*********************************************************************************************************************************

#ifndef FRACTION_HPP
#define FRACTION_HPP

  // Standard C++ library header files

#include <cstdint>
#include <exception>
#include <stdexcept>

  // MCL library header files

#include <include/functions/gcd.hpp>

namespace MCL
{

  class fraction_t
  {
  private:
    std::int64_t numerator_ = 0;
    std::int64_t denominator_ = 1;

    void normalise()
    {
      int sign = 1;
      if (numerator_ < 0)
      {
        sign *= -1;
        numerator_ = -numerator_;
      };
      if (denominator_ < 0)
      {
        sign *= -1;
        denominator_ = -denominator_;
      };

      std::int64_t temp = gcd(numerator_, denominator_);
      numerator_ /= temp * sign;
      denominator_ /= temp;
    }

  protected:
  public:
    fraction_t() {}
    fraction_t(std::int64_t n, std::int64_t d) : numerator_(n), denominator_(d)
    {
      if (d == 0)
      {
        throw std::invalid_argument("CFraction::CFraction denominator cannot be zero.");
      }
      else if (n == 0)
      {
        numerator_ = 0;
        denominator_ = 1;
      };
      normalise();
    }
    fraction_t(fraction_t const &other) : numerator_(other.numerator_), denominator_(other.denominator_) {}

    std::int64_t &numerator() { return numerator_; }
    std::int64_t &denominator() { return denominator_; }

    operator std::int64_t() { return static_cast<std::int64_t>(numerator_) / static_cast<std::int64_t>(denominator_); }
    operator float() { return static_cast<float>(numerator_) / static_cast<float>(denominator_); }
    operator double() { return static_cast<double>(numerator_) / static_cast<double>(denominator_); }

    fraction_t &operator+=(fraction_t const &rhs)
    {
       std::int64_t temp = denominator_ * rhs.denominator_;
       numerator_ = numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_;
       denominator_ = temp;

       normalise();
       return *this;
    }

    fraction_t operator+(fraction_t const &rhs)
    {
      fraction_t temp(*this);
      temp += rhs;
      return temp;
    }

    fraction_t &operator -=(fraction_t const &rhs)
    {
      std::int64_t temp = denominator_ * rhs.denominator_;
      numerator_ = numerator_ * rhs.denominator_ - rhs.numerator_ * denominator_;
      denominator_ = temp;

      normalise();
      return *this;
    }

    fraction_t operator-(fraction_t const &rhs)
    {
      fraction_t temp(*this);
      temp -= rhs;
      return temp;
    }

    fraction_t &operator*=(fraction_t const &rhs)
    {
      numerator_ *= rhs.numerator_;
      denominator_ *= rhs.denominator_;

      normalise();
      return *this;
    }

    fraction_t operator*(fraction_t const &rhs)
    {
      fraction_t temp(*this);
      temp *= rhs;
      return temp;
    }

    fraction_t &operator/=(fraction_t const rhs)
    {
      numerator_ *= rhs.denominator_;
      denominator_ *= rhs.numerator_;

      normalise();
      return *this;
    }

    fraction_t operator/(fraction_t const &rhs)
    {
      fraction_t temp(*this);
      temp /= rhs;
      return temp;
    }

  };
}

#endif // FRACTION_HPP
