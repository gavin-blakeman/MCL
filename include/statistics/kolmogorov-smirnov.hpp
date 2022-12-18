#ifndef KOLMOGOROVSMIRNOV_HPP
#define KOLMOGOROVSMIRNOV_HPP

  // Standard C++ library

#include <valarray>

  // MCL library

#include "../config.h"
#include "minmax.hpp"

namespace MCL
{
  template<typename T>
  T kolmogorov_smirnow(std::valarray<T> const &F, std::valarray<T> const &G)
  {
    std::size_t indx;

    FP_t Fs = F.sum();
    FP_t Gs = G.sum();

    std::valarray<FP_t> Fc(F.size());
    std::valarray<FP_t> Gc(G.size());

    for (indx = 0; indx < F.size(); indx++)
    {
      Fc[indx] = static_cast<FP_t>(F[indx]) / Fs;
    }

    for (indx = 0; indx < G.size(); indx++)
    {
      Gc[indx] = static_cast<FP_t>(G[indx]) / Gs;
    }

    std::valarray<FP_t> D = std::abs(Fc - Gc);
    Gmax = MCL::max(D);
  }
}

#endif // KOLMOGOROVSMIRNOV_HPP
