#ifndef PERCENTILE_HPP
#define PERCENTILE_HPP

  // Standard C++ library

#include <algorithm>
#include <valarray>


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
    std::size_t s = 0;

    if (va.size() > 1)
    {
      s = p * (va.size() +1) / 100;

      std::sort(std::begin(va), std::end(va));
    };

    return va[s];
  }


} // namespace

#endif // PERCENTILE_HPP
