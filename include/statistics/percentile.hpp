#ifndef PERCENTILE_HPP
#define PERCENTILE_HPP

  // Standard C++ library

#include <algorithm>
#include <cmath>
#include <valarray>

#include "../config.h"

namespace MCL
{

  /// @brief Returns the percentile requested from the array.
  /// @note 1. This is an expensive function. The valarray is copied to the function. Once copied the valarray is sorte and then the
  ///          percentile extracted.
  /// @note 2. See also the median and mode functions. That also require to valarray to be sorted.
  /// @param[in] va: The valarray to find the percentile.
  /// @param[in] p: The percentile to find. (10 = 10%)
  /// @throws
  /// @version 2022-12-02/GGB - Function created.

  template<typename T, typename U>
  T percentile(std::valarray<T> va, U p)
  {
    if (p == 0)
    {
      return 0;
    }
    else if (va.size() == 0)
    {
      return 0;
    }
    else
    {
      std::size_t s1 = 0;
      std::size_t s2 = 0;

      std::sort(std::begin(va), std::end(va));

      FP_t d = (static_cast<FP_t>(p) / 100.0f) * static_cast<FP_t>(va.size() + 1);
      s1 = static_cast<std::size_t>(std::floor(d)) - 1;
      s2 = static_cast<std::size_t>(std::ceil(d)) - 1;

      s1 = std::min(s1, va.size() - 1);
      s2 = std::min(s2, va.size() - 1);

      if (s1 == s2)
      {
        return va[s1];
      }
      else
      {
        d -= std::floor(d);
        d *= (va[s2] - va[s1]);
        return va[s1] + d;
      }


    };
  }


} // namespace

#endif // PERCENTILE_HPP
