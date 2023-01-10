//*********************************************************************************************************************************
//
// PROJECT:							Math Class Library
// FILE:								statistics/disributionFunctions/weibull.hpp
// SUBSYSTEM:						Statistics Functions
// LANGUAGE:						C++
// TARGET OS:						WINDOWS/UNIX/LINUX/MAC
// LIBRARY DEPENDANCE:	boost
// NAMESPACE:						MCL
// AUTHOR:							Gavin Blakeman.
// LICENSE:             GPLv2
//
//                      Copyright 2022 Gavin Blakeman.
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
// HISTORY:             2022-12-21 GGB - File created.
//
//*********************************************************************************************************************************

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
