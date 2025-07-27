/*
 * vectorN.hpp
 *
 *  Created on: 26 July 2025
 *      Author: gavin
 */

#ifndef MCL_INCLUDE_VECTORN_HPP_
#define MCL_INCLUDE_VECTORN_HPP_

#include <cstdint>
#include <tuple>
#include <valarray>

namespace MCL
{
  /// @tparam T = Type of numeric.
  /// @N = Number of dimensions.

  template<typename T, std::uint8_t N>
  class vectorN
  {
  public:
    using axisType_t = std::uint8_t;

    vectorN() : value(N) {}
    ~vectorN() = default;
    vectorN(vectorN const &) = default;
    vectorN(vectorN &&) = default;
    vectorN &operator=(vectorN const &) = default;
    vectorN &operator=(vectorN &&) = delete;

    template<typename... Args>
    constexpr vectorN &operator=(Args &&... args)
    {
      value = {{ args... }};
    }

    T &operator[](axisType_t n)
    {
      return value[n];
    }

    T const &operator[](axisType_t n) const
    {
      return value[n];
    }

    vectorN &operator+=(vectorN rhs)
    {
      value += rhs.value;
      return *this; // return the result by value (uses move constructor)
    }

    vectorN operator+(vectorN rhs)
    {
      vectorN rv(*this);
      rv.value += rhs.value;
      return rv; // return the result by value (uses move constructor)
    }

    vectorN &operator-=(vectorN rhs)
    {
      value -= rhs.value;
      return *this; // return the result by value (uses move constructor)
    }

    vectorN operator-(vectorN rhs)
    {
      vectorN rv(*this);
      rv.value -= rhs.value;
      return rv; // return the result by value (uses move constructor)
    }

    template<typename VT>
    vectorN &operator*=(VT rhs)
    {
      value *= rhs;
      return *this; // return the result by value (uses move constructor)
    }



  private:
    std::valarray<T> value;

    template<typename VT>
    friend vectorN operator*(vectorN lhs, VT rhs)
    {
      lhs *= rhs;
      return lhs; // return the result by value (uses move constructor)
    }
  };

}

#endif /* MCL_INCLUDE_VECTORN_HPP_ */
