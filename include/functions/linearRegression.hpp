#ifndef LINEARREGRESSION_HPP
#define LINEARREGRESSION_HPP

  // Standard C++ library

#include <exception>
#include <iostream>
#include <utility>
#include <valarray>

  // MCL library

#include "../config.h"
#include "../functions.hpp"

namespace MCL
{

  /// @brief Determines the slope and intercept of the least squares fit line for a number of data points. This is the closed
  ///        form (non-matrix) and is trivial.
  /// @param[in] X: The X-values
  /// @param[in] Y: The Y-values
  /// @returns the slope (first) and intercept (second). (m, C)
  /// @throws
  /// @version 2022-12-17/GGB - Function created.

  template<typename T>
  std::pair<T, T> linearRegression(std::valarray<T> const &X, std::valarray<T> const &Y)
  {
#ifndef TEST
    RUNTIME_ASSERT(X.size() == Y.size(), "valarrays must be equal size");
#endif

    FP_t Sx, Sy, Sxx = 0, Syy = 0, Sxy = 0, m, c, n;

    n = X.size();

    Sx = X.sum();
    Sy = Y.sum();

    for (std::size_t indx = 0; indx < X.size(); indx++)
    {
      Sxx += pow2(X[indx]);
      Syy += pow2(Y[indx]);
      Sxy += X[indx] * Y[indx];
    }

    m = (n * Sxy - Sx * Sy) / (n * Sxx - pow2(Sx));
    c = Sy / n - m / n * Sx;

    return std::make_pair(m, c);
  }

}

#endif // LINEARREGRESSION_HPP
