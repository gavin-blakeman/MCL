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

#include "include/numeric.h"

  // MCL Includes

#include "include/exceptions.h"

  // GCL Header files

#include <GCL>

namespace MCL
{

  /// @brief Default constructor
  /// @throws None.
  /// @version 2015-08-23/GGB - Function created.

  CNumeric::CNumeric() : storedType(NT_none)
  {

  }

  /// @brief Constructor taking a uint8_t
  /// @param[in] v - new value.

  CNumeric::CNumeric(std::uint8_t v)
  {
    storedType = NT_uint8;
    value.uint8Value = v;
  }

  /// @brief Constructor taking a uint16_t
  /// @param[in] v - new value.

  CNumeric::CNumeric(std::uint16_t v)
  {
    storedType = NT_uint16;
    value.uint16Value = v;
  }

  /// @brief Constructor taking a uint32_t
  /// @param[in] v - new value.

  CNumeric::CNumeric(std::uint32_t v)
  {
    storedType = NT_uint32;
    value.uint32Value = v;
  }

  /// @brief Constructor taking a uint64_t
  /// @param[in] v - new value.

  CNumeric::CNumeric(std::uint64_t v)
  {
    storedType = NT_uint64;
    value.uint64Value = v;
  }

  /// @brief Constructor taking a int8_t
  /// @param[in] v - new value.

  CNumeric::CNumeric(std::int8_t v)
  {
    storedType = NT_int8;
    value.int8Value = v;
  }

  /// @brief Constructor taking a int8_t
  /// @param[in] v - new value.

  CNumeric::CNumeric(std::int16_t v)
  {
    storedType = NT_int16;
    value.int16Value = v;
  }

  /// @brief Constructor taking a int8_t
  /// @param[in] v - new value.

  CNumeric::CNumeric(std::int32_t v)
  {
    storedType = NT_int32;
    value.int32Value = v;
  }

  /// @brief Constructor taking a int8_t
  /// @param[in] v - new value.

  CNumeric::CNumeric(std::int64_t v)
  {
    storedType = NT_int64;
    value.int64Value = v;
  }

  /// @brief Constructor taking a float
  /// @param[in] v - new value.

  CNumeric::CNumeric(float v)
  {
    storedType = NT_float;
    value.floatValue = v;
  }

  /// @brief Constructor taking a float
  /// @param[in] v - new value.

  CNumeric::CNumeric(double v)
  {
    storedType = NT_double;
    value.doubleValue = v;
  }

  /// @brief Returns the value as an 8 bit unsigned integer
  /// @returns The stored value as std::uint8_t
  /// @throws 0x1000 - NUMERIC: Value out of range.
  //
  // 2015-07-08/GGB - Function created.

  CNumeric::operator std::uint8_t() const
  {
    std::uint8_t returnValue;

    switch (storedType)
    {
      case NT_uint8:
      {
        returnValue = value.uint8Value;
        break;
      };
      case NT_uint16:
      {
        if (value.uint16Value > std::numeric_limits<std::uint8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint8_t>(value.uint16Value);
        };
        break;
      };
      case NT_uint32:
      {
        if (value.uint32Value > std::numeric_limits<std::uint8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint8_t>(value.uint32Value);
        };
        break;
      };
      case NT_uint64:
      {
        if (value.uint64Value > std::numeric_limits<std::uint8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint8_t>(value.uint64Value);
        };
        break;
      };
      case NT_int8:
      {
        if (value.int8Value < std::numeric_limits<std::uint8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int8Value > std::numeric_limits<std::uint8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint8_t>(value.int8Value);
        };
        break;
      };
      case NT_int16:
      {
        if (value.int16Value < std::numeric_limits<std::uint8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int16Value > std::numeric_limits<std::uint8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint8_t>(value.int16Value);
        };
        break;
      };
      case NT_int32:
      {
        if (value.int32Value < std::numeric_limits<std::uint8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int32Value > std::numeric_limits<std::uint8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint8_t>(value.int32Value);
        };
        break;
      };
      case NT_int64:
      {
        if (value.int64Value < std::numeric_limits<std::uint8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int64Value > std::numeric_limits<std::uint8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint8_t>(value.int64Value);
        };
        break;
      };
      case NT_float:
      {
        if (value.floatValue < std::numeric_limits<std::uint8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.floatValue > std::numeric_limits<std::uint8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint8_t>(value.floatValue);
        };
        break;
      };
      case NT_double:
      {
        if (value.doubleValue < std::numeric_limits<std::uint8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.doubleValue > std::numeric_limits<std::uint8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint8_t>(value.doubleValue);
        };
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

  /// @brief Returns the value as an 16 bit unsigned integer
  /// @returns The stored value as std::uint16_t
  /// @throws 0x1000 - NUMERIC: Value out of range.
  /// @version 2015-07-08/GGB - Function created.

  CNumeric::operator std::uint16_t() const
  {
    std::uint16_t returnValue;

    switch (storedType)
    {
      case NT_uint8:
      {
        returnValue = static_cast<std::uint16_t>(value.uint8Value);
        break;
      };
      case NT_uint16:
      {
        returnValue = value.uint16Value;
        break;
      };
      case NT_uint32:
      {
        if (value.uint32Value > std::numeric_limits<std::uint16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint16_t>(value.uint32Value);
        };
        break;
      };
      case NT_uint64:
      {
        if (value.uint64Value > std::numeric_limits<std::uint16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint16_t>(value.uint64Value);
        };
        break;
      };
      case NT_int8:
      {
        if (value.int8Value < std::numeric_limits<std::uint16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int8Value > std::numeric_limits<std::uint16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint16_t>(value.int8Value);
        };
        break;
      };
      case NT_int16:
      {
        if (value.int16Value < std::numeric_limits<std::uint16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int16Value > std::numeric_limits<std::uint16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint16_t>(value.int16Value);
        };
        break;
      };
      case NT_int32:
      {
        if (value.int32Value < std::numeric_limits<std::uint16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int32Value > std::numeric_limits<std::uint16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint16_t>(value.int32Value);
        };
        break;
      };
      case NT_int64:
      {
        if (value.int64Value < std::numeric_limits<std::uint16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int64Value > std::numeric_limits<std::uint16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint16_t>(value.int64Value);
        };
        break;
      };
      case NT_float:
      {
        if (value.floatValue < std::numeric_limits<std::uint16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.floatValue > std::numeric_limits<std::uint16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint16_t>(value.floatValue);
        };
        break;
      };
      case NT_double:
      {
        if (value.doubleValue < std::numeric_limits<std::uint16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.doubleValue > std::numeric_limits<std::uint16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint16_t>(value.doubleValue);
        };
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

  /// @brief Returns the value as an 32 bit unsigned integer
  /// @returns The stored value as std::uint32_t
  /// @throws 0x1000 - NUMERIC: Value out of range.
  /// @version 2015-07-08/GGB - Function created.

  CNumeric::operator uint32_t() const
  {
    std::uint32_t returnValue;

    switch (storedType)
    {
      case NT_uint8:
      {
        returnValue = value.uint8Value;
        break;
      };
      case NT_uint16:
      {
        returnValue = value.uint16Value;
        break;
      };
      case NT_uint32:
      {
        returnValue = value.uint32Value;
        break;
      };
      case NT_uint64:
      {
        if (value.uint64Value > std::numeric_limits<std::uint32_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint32_t>(value.uint64Value);
        };
        break;
      };
      case NT_int8:
      {
        if (value.int8Value < 0)
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint32_t>(value.int8Value);
        };
        break;
      };
      case NT_int16:
      {
        if (value.int16Value < 0)
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint32_t>(value.int16Value);
        };
        break;
      };
      case NT_int32:
      {
        if (value.int32Value < 0)
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint32_t>(value.int32Value);
        };
        break;
      };
      case NT_int64:
      {
        if (value.int64Value < std::numeric_limits<std::uint32_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int64Value > std::numeric_limits<std::uint32_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint32_t>(value.int64Value);
        };
        break;
      };
      case NT_float:
      {
        if (value.floatValue < std::numeric_limits<std::uint32_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.floatValue > std::numeric_limits<std::uint32_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint32_t>(value.floatValue);
        };
        break;
      };
      case NT_double:
      {
        if (value.doubleValue < std::numeric_limits<std::uint32_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.doubleValue > std::numeric_limits<std::uint32_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint32_t>(value.doubleValue);
        };
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

  /// @brief Returns the value as an 64 bit unsigned integer
  /// @returns The stored value as std::uint64_t
  /// @throws 0x1000 - NUMERIC: Value out of range.
  /// @version 2015-07-08/GGB - Function created.

  CNumeric::operator uint64_t() const
  {
    std::uint64_t returnValue;

    switch (storedType)
    {
      case NT_uint8:
      {
        returnValue = value.uint8Value;
        break;
      };
      case NT_uint16:
      {
        returnValue = value.uint16Value;
        break;
      };
      case NT_uint32:
      {
        returnValue = value.uint32Value;
        break;
      };
      case NT_uint64:
      {
        returnValue = value.uint64Value;
        break;
      };
      case NT_int8:
      {
        if (value.int8Value < 0)
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint64_t>(value.int8Value);
        };
        break;
      };
      case NT_int16:
      {
        if (value.int16Value < 0)
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint64_t>(value.int16Value);
        };
        break;
      };
      case NT_int32:
      {
        if (value.int32Value < 0)
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint64_t>(value.int32Value);
        };
        break;
      };
      case NT_int64:
      {
        if (value.int64Value < 0)
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint64_t>(value.int64Value);
        };
        break;
      };
      case NT_float:
      {
        if (value.floatValue < std::numeric_limits<std::uint64_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.floatValue > std::numeric_limits<std::uint64_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint64_t>(value.floatValue);
        };
        break;
      };
      case NT_double:
      {
        if (value.doubleValue < std::numeric_limits<std::uint64_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.doubleValue > std::numeric_limits<std::uint64_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::uint64_t>(value.doubleValue);
        };
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

  /// @brief Returns the value as an 8 bit integer
  /// @returns The stored value as std::int8_t
  /// @throws 0x1000 - NUMERIC: Value out of range.
  /// @version 2015-07-08/GGB - Function created.

  CNumeric::operator int8_t() const
  {
    std::int8_t returnValue;

    switch (storedType)
    {
      case NT_int8:
      {
        returnValue = value.int8Value;
        break;
      };
      case NT_uint8:
      {
        if (value.uint8Value > std::numeric_limits<std::int8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int8_t>(value.uint8Value);
        }
        break;
      };
      case NT_uint16:
      {
        if (value.uint16Value > std::numeric_limits<std::int8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int8_t>(value.uint16Value);
        };
        break;
      };
      case NT_uint32:
      {
        if (value.uint32Value > std::numeric_limits<std::int8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int8_t>(value.uint32Value);
        };
        break;
      };
      case NT_uint64:
      {
        if (value.uint64Value > std::numeric_limits<std::int8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int8_t>(value.uint64Value);
        };
        break;
      };
      case NT_int16:
      {
        if (value.int16Value < std::numeric_limits<std::int8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int16Value > std::numeric_limits<std::int8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int8_t>(value.int16Value);
        };
        break;
      };
      case NT_int32:
      {
        if (value.int32Value < std::numeric_limits<std::int8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int32Value > std::numeric_limits<std::int8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int8_t>(value.int32Value);
        };
        break;
      };
      case NT_int64:
      {
        if (value.int64Value < std::numeric_limits<std::int8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int64Value > std::numeric_limits<std::int8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int8_t>(value.int64Value);
        };
        break;
      };
      case NT_float:
      {
        if (value.floatValue < std::numeric_limits<std::int8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.floatValue > std::numeric_limits<std::int8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int8_t>(value.floatValue);
        };
        break;
      };
      case NT_double:
      {
        if (value.doubleValue < std::numeric_limits<std::int8_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.doubleValue > std::numeric_limits<std::int8_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int8_t>(value.doubleValue);
        };
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

  /// @brief Returns the value as an 16 bit integer
  /// @returns The stored value as std::int16_t
  /// @throws 0x1000 - NUMERIC: Value out of range.
  /// @version 2015-07-08/GGB - Function created.

  CNumeric::operator std::int16_t() const
  {
    std::int16_t returnValue;

    switch (storedType)
    {
      case NT_uint8:
      {
        returnValue = static_cast<std::int16_t>(value.uint8Value);
        break;
      };
      case NT_uint16:
      {
        if (value.uint16Value > std::numeric_limits<std::int16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int16_t>(value.uint16Value);
        };
        break;
      };
      case NT_uint32:
      {
        if (value.uint32Value > std::numeric_limits<std::int16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int16_t>(value.uint32Value);
        };
        break;
      };
      case NT_uint64:
      {
        if (value.uint64Value > std::numeric_limits<std::int16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int16_t>(value.uint64Value);
        };
        break;
      };
      case NT_int8:
      {
        returnValue = value.int8Value;
        break;
      };
      case NT_int16:
      {
        returnValue = value.int16Value;
        break;
      };
      case NT_int32:
      {
        if (value.int32Value < std::numeric_limits<std::int16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int32Value > std::numeric_limits<std::int16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int16_t>(value.int32Value);
        };
        break;
      };
      case NT_int64:
      {
        if (value.int64Value < std::numeric_limits<std::int16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int64Value > std::numeric_limits<std::int16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int16_t>(value.int64Value);
        };
        break;
      };
      case NT_float:
      {
        if (value.floatValue < std::numeric_limits<std::int16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.floatValue > std::numeric_limits<std::int16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int16_t>(value.floatValue);
        };
        break;
      };
      case NT_double:
      {
        if (value.doubleValue < std::numeric_limits<std::int16_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.doubleValue > std::numeric_limits<std::int16_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int16_t>(value.doubleValue);
        };
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

  /// @brief Returns the value as an 32 bit integer
  /// @returns The stored value as std::int32_t
  /// @throws 0x1000 - NUMERIC: Value out of range.
  /// @version 2015-07-08/GGB - Function created.

  CNumeric::operator std::int32_t() const
  {
    std::int32_t returnValue;

    switch (storedType)
    {
      case NT_uint8:
      {
        returnValue = static_cast<std::int32_t>(value.uint8Value);
        break;
      };
      case NT_uint16:
      {
        returnValue = static_cast<std::int32_t>(value.uint16Value);
        break;
      };
      case NT_uint32:
      {
        if (value.uint32Value > std::numeric_limits<std::int32_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int32_t>(value.uint32Value);
        };
        break;
      };
      case NT_uint64:
      {
        if (value.uint64Value > std::numeric_limits<std::int32_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int32_t>(value.uint64Value);
        };
        break;
      };
      case NT_int8:
      {
        returnValue = value.int8Value;
        break;
      };
      case NT_int16:
      {
        returnValue = value.int16Value;
        break;
      };
      case NT_int32:
      {
        returnValue = value.int32Value;
        break;
      };
      case NT_int64:
      {
        if (value.int64Value < std::numeric_limits<std::int32_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.int64Value > std::numeric_limits<std::int32_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int32_t>(value.int64Value);
        };
        break;
      };
      case NT_float:
      {
        if (value.floatValue < std::numeric_limits<std::int32_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.floatValue > std::numeric_limits<std::int32_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int32_t>(value.floatValue);
        };
        break;
      };
      case NT_double:
      {
        if (value.doubleValue < std::numeric_limits<std::int32_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.doubleValue > std::numeric_limits<std::int32_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int32_t>(value.doubleValue);
        };
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

  /// @brief Returns the value as an 64 bit integer
  /// @returns The stored value as std::int64_t
  /// @throws 0x1000 - NUMERIC: Value out of range.
  /// @version 2015-07-08/GGB - Function created.

  CNumeric::operator std::int64_t() const
  {
    std::int64_t returnValue;

    switch (storedType)
    {
      case NT_uint8:
      {
        returnValue = static_cast<std::int64_t>(value.uint8Value);
        break;
      };
      case NT_uint16:
      {
        returnValue = static_cast<std::int64_t>(value.uint16Value);
        break;
      };
      case NT_uint32:
      {
        returnValue = static_cast<std::int64_t>(value.uint32Value);
        break;
      };
      case NT_uint64:
      {
        if (value.uint64Value > std::numeric_limits<std::int64_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int64_t>(value.uint64Value);
        };
        break;
      };
      case NT_int8:
      {
        returnValue = value.int8Value;
        break;
      };
      case NT_int16:
      {
        returnValue = value.int16Value;
        break;
      };
      case NT_int32:
      {
        returnValue = value.int32Value;
        break;
      };
      case NT_int64:
      {
        returnValue = value.int64Value;
        break;
      };
      case NT_float:
      {
        if (value.floatValue < std::numeric_limits<std::int64_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.floatValue > std::numeric_limits<std::int64_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int64_t>(value.floatValue);
        };
        break;
      };
      case NT_double:
      {
        if (value.doubleValue < std::numeric_limits<std::int64_t>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.doubleValue > std::numeric_limits<std::int64_t>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<std::int64_t>(value.doubleValue);
        };
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

  /// @brief Returns the value as an float value
  /// @returns The stored value as a float
  /// @throws 0x1000 - NUMERIC: Value out of range.
  //
  // 2015-07-08/GGB - Function created.

  CNumeric::operator float() const
  {
    float returnValue;

    switch (storedType)
    {
      case NT_uint8:
      {
        returnValue = value.uint8Value;
        break;
      };
      case NT_uint16:
      {
        returnValue = value.uint16Value;
        break;
      };
      case NT_uint32:
      {
        returnValue = value.uint32Value;
        break;
      };
      case NT_uint64:
      {
        returnValue = value.uint64Value;
        break;
      };
      case NT_int8:
      {
        returnValue = value.int8Value;
        break;
      };
      case NT_int16:
      {
        returnValue = value.int16Value;
        break;
      };
      case NT_int32:
      {
        returnValue = value.int32Value;
        break;
      };
      case NT_int64:
      {
        returnValue = value.int64Value;
        break;
      };
      case NT_float:
      {
        returnValue = value.floatValue;
        break;
      };
      case NT_double:
      {
        if (value.doubleValue < std::numeric_limits<float>::min())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else if (value.doubleValue > std::numeric_limits<float>::max())
        {
          ERRORMESSAGE("NUMERIC: Value out of range.");
        }
        else
        {
          returnValue = static_cast<float>(value.doubleValue);
        };
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

  /// @brief Returns the value as an double value
  /// @returns The stored value as a double
  /// @throws 0x1000 - NUMERIC: Value out of range.
  //
  // 2015-07-08/GGB - Function created.

  CNumeric::operator double() const
  {
    double returnValue;

    switch (storedType)
    {
      case NT_uint8:
      {
        returnValue = value.uint8Value;
        break;
      };
      case NT_uint16:
      {
        returnValue = value.uint16Value;
        break;
      };
      case NT_uint32:
      {
        returnValue = value.uint32Value;
        break;
      };
      case NT_uint64:
      {
        returnValue = value.uint64Value;
        break;
      };
      case NT_int8:
      {
        returnValue = value.int8Value;
        break;
      };
      case NT_int16:
      {
        returnValue = value.int16Value;
        break;
      };
      case NT_int32:
      {
        returnValue = value.int32Value;
        break;
      };
      case NT_int64:
      {
        returnValue = value.int64Value;
        break;
      };
      case NT_float:
      {
        returnValue = value.floatValue;
        break;
      };
      case NT_double:
      {
        returnValue = static_cast<float>(value.doubleValue);
        break;
      };
      case NT_none:
      default:
      {
        CODE_ERROR();
        break;
      };
    }

    return returnValue;
  }

} // namespace MCL
