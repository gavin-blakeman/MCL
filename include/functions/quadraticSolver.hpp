/*
 * quadraticSolver.hpp
 *
 *  Created on: 26 July 2025
 *      Author: gavin
 */

#ifndef MCL_INCLUDE_FUNCTIONS_QUADRATICSOLVER_HPP_
#define MCL_INCLUDE_FUNCTIONS_QUADRATICSOLVER_HPP_

#include <utility>

#include "include/functions.hpp"

namespace MCL
{

  template<typename F>
  std::pair<F, F> quadraticSolver(F A, F B, F C)
  {
    F b2term = std::sqrt(MCL::pow2(B) - 4 * A * C);
    F ax2 = A * 2;

    return std::make_pair((-B - b2Term)/ax2, (-B + b2Term)/ax2);
  }

}

#endif /* MCL_INCLUDE_FUNCTIONS_QUADRATICSOLVER_HPP_ */
