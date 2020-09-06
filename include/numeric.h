//**********************************************************************************************************************************
//
// PROJECT:							MCL (Math Class Library)
// FILE:								numeric
// SUBSYSTEM:						Numeric classes.
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	None
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2015, 2017-2020 Gavin Blakeman.
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
// OVERVIEW:            The CNumeric class provides a class with a type that can be selected on the fly.
//
// HISTORY:             2015-09-22 GGB - astroManager 2015.09 release
//                      2015-07-07 GGB - File Created.
//
//**********************************************************************************************************************************

#ifndef NUMERIC_HPP
#define NUMERIC_HPP

  // Standard C++ library header files.

#include <cstdint>
#include <limits>

  // MCL Library

#include "config.h"

namespace MCL
{
  enum ENumericType
  {
    NT_none,
    NT_uint8 = 8,
    NT_uint16 = 20,
    NT_uint32 = 40,
    NT_uint64,
    NT_int8 = 10,
    NT_int16 = 16,
    NT_int32 = 32,
    NT_int64 = 64,
    NT_float = -32,
    NT_double = -64
  };

  class CNumeric
  {
  private:
    union UValue
    {
      std::uint8_t uint8Value;
      std::uint16_t uint16Value;
      std::uint32_t uint32Value;
      std::uint64_t uint64Value;
      std::int8_t int8Value;
      std::int16_t int16Value;
      std::int32_t int32Value;
      std::int64_t int64Value;
      float floatValue;
      double doubleValue;
    };

    UValue value;
    ENumericType storedType;

  protected:
  public:
    CNumeric();
    CNumeric(std::uint8_t);
    CNumeric(std::uint16_t);
    CNumeric(std::uint32_t);
    CNumeric(std::uint64_t);
    CNumeric(std::int8_t);
    CNumeric(std::int16_t);
    CNumeric(std::int32_t);
    CNumeric(std::int64_t);
    CNumeric(float);
    CNumeric(double);

    operator std::int8_t() const;
    operator std::int16_t() const;
    operator std::int32_t() const;
    operator std::int64_t() const;

    operator std::uint8_t() const;
    operator std::uint16_t() const;
    operator std::uint32_t() const;
    operator std::uint64_t() const;

    operator float() const;
    operator double() const;

  };

} // namespace MCL

#endif // NUMERIC_HPP
