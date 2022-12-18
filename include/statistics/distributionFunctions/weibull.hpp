#ifndef WEIBULL_HPP
#define WEIBULL_HPP

  // Standard C++ library

#include <cmath>
#include <utility>
#include <valarray>

  // MCL Library

#include "../../functions/linearRegression.hpp"
#include "../../utility/sort.hpp"

namespace MCL
{
  template<typename T>
  std::pair<T, T> weibull_regression(std::valarray<T> const &N)
  {
    std::size_t indx;

    std::valarray<T> Ns(N);

    MCL::sort(std::begin(Ns), std::end(Ns));     // Sort the array

    std::valarray<T> X(std::log(Ns));
    std::valarray<T> Y(X.size());

    T n = 1 / static_cast<T>(N.size());

    for (indx = 0; indx < X.size(); indx++)
    {
     Y[indx] = std::log(-std::log(1 - ((static_cast<T>(indx) + 0.5) * n)));
    }

    std::pair<T, T> r = linearRegression(X, Y);

    std::pair<T, T> rv;

    rv.second = r.first;
    rv.first = std::exp(-r.second / r.first);

    return rv;

  }
}

#endif // WEIBULL_HPP
