#ifndef ANDERSONDARLING_HPP
#define ANDERSONDARLING_HPP

  // Standard C++ library header files

#include <cmath>
#include <functional>
#include <map>
#include <stdexcept>
#include <valarray>

  // Miscellaneous library header files

#include "boost/math/distributions.hpp"

  // MCL header files

#include "../config.h"
#include "../functions.hpp"
#include "../definitions.h"
#include "../utility/sort.hpp"

namespace MCL
{
  using criticalValues_t = std::map<FP_t, FP_t>;

  criticalValues_t const criticalValues_normal_a = { { 0.005, 1.1578 },
                                                     { 0.01, 1.0348 },
                                                     { 0.025, 0.8728 },
                                                     { 0.05, 0.7514 },
                                                     { 0.10, 0.6305 },
                                                     { 0.20, 0.5091 },
                                                   };

  criticalValues_t const criticalValues_normal_b = { { 0.005, 1.063 },
                                                     { 0.01, 1.013 },
                                                     { 0.025, 0.881 },
                                                     { 0.05, 0.795 },
                                                     { 0.10, 0.750 },
                                                     { 0.20, 0.756 },
                                                   };

  criticalValues_t const criticalValues_normal_d = { { 0.005, 1.34},
                                                     { 0.01, 0.93 },
                                                     { 0.025, 0.94 },
                                                     { 0.05, 0.89 },
                                                     { 0.10, 0.80 },
                                                     { 0.20, 0.39 },
                                                   };

  criticalValues_t const criticalValues_weibull = { { 0.01, 1.038 },
                                                    { 0.025, 0.877 },
                                                    { 0.05, 0.757 },
                                                    { 0.10, 0.637 },
                                                    { 0.25, 0.474 },
                                                  };

  criticalValues_t const criticalValues_exponential = { { 0.0025, 2.534 },
                                                        { 0.005, 2.244 },
                                                        { 0.01, 1.959 },
                                                        { 0.025, 1.591 },
                                                        { 0.05, 1.321 },
                                                        { 0.10, 1.062 },
                                                        { 0.15, 0.916 },
                                                        { 0.20, 0.816 },
                                                        { 0.25, 0.736 },
                                                      };

  criticalValues_t const criticalValues_specified = { { 0.001, 5.9671 },
                                                      { 0.005, 4.4971 },
                                                      { 0.01, 3.8784 },
                                                      { 0.025, 3.0775 },
                                                      { 0.05, 2.4922 },
                                                      { 0.1, 1.9330 },
                                                      { 0.15, 1.6212 },
                                                      { 0.25, 1.2479 },
                                                    };

  criticalValues_t const criticalValues_gamma_1 = { { 0.005, 1.227 },
                                                  { 0.01, 1.092 },
                                                  { 0.025, 0.917 },
                                                  { 0.05, 0.786 },
                                                  { 0.10, 0.657 },
                                                  { 0.25, 0.486 },
                                                };
  criticalValues_t const criticalValues_gamma_2 = { { 0.005, 1.190 },
                                                    { 0.01, 1.062 },
                                                    { 0.025, 0.894 },
                                                    { 0.05, 0.768 },
                                                    { 0.01, 0.643 },
                                                    { 0.25, 0.486 }
                                                  };
  criticalValues_t const criticalValues_gamma_3 = { { 0.005, 1.178 },
                                                    { 0.01, 1.052 },
                                                    { 0.025, 0.886 },
                                                    { 0.05, 0.762 },
                                                    { 0.10, 0.639 },
                                                    { 0.25, 0.475},
                                                  };
  criticalValues_t const criticalValues_gamma_4 = { { 0.005, 1.173 },
                                                    { 0.01, 1.048 },
                                                    { 0.025, 0.833 },
                                                    { 0.05, 0.759 },
                                                    { 0.10, 0.637 },
                                                    { 0.25, 0.473 },
                                                  };
  criticalValues_t const criticalValues_gamma_5;
  criticalValues_t const criticalValues_gamma_6;
  criticalValues_t const criticalValues_gamma_8;
  criticalValues_t const criticalValues_gamma_10;
  criticalValues_t const criticalValues_gamma_12;
  criticalValues_t const criticalValues_gamma_15;
  criticalValues_t const criticalValues_gamma_20;
  criticalValues_t const criticalValues_gamma_gt;



  struct goodnessOfFit_t
  {
    PDF_e PDF;                      ///< Distribution function to test.
    std::vector<FP_t> parameters;   ///< PDF parameters. (Specific to the PDF.)
    FP_t alpha;
    bool H0 = false;

  };

  /* PDF Parameters
   * Normal: [0] = Mean, [1] = stDev
   * Weibull: [0] = alpha, [1] = beta
   */


  /// @brief Performs an Anderson-Darling goodness of fit test on the passed data. The function can test against multiple
  ///        PDF's with the results being returned in the passed vector.
  /// @param[in] X: The data to test
  /// @param[in/out] results: A vector of the distributions to test and the results obtained.

  template<typename T>
  void anderson_darling_1S(std::valarray<T> const &X, std::vector<goodnessOfFit_t> &results)
  {
    std::size_t indx;
    std::size_t N = X.size();

    std::valarray<T> X_(X);
    MCL::sort(std::begin(X_), std::end(X_));     // Sort the array

      // Loop over each PDF requested to be tested.

    for (auto &GOF: results)
    {
      std::function<FP_t(FP_t)> fn_cdf;

      switch (GOF.PDF)
      {
        case PDF_NORMAL:
        {
          if (GOF.parameters.size() < 2)
          {
            throw std::runtime_error("Too few parameters for PDF:Normal. Two (2) required.");
          }
          else
          {
            fn_cdf = [GOF](FP_t p)
            {
              boost::math::normal_distribution normal(GOF.parameters[0], GOF.parameters[1]);
              return boost::math::cdf(normal, p);
            };
          }
          break;
        }
        case PDF_EXPONENTIAL:
        {
          if (GOF.parameters.size() < 1)
          {
            throw std::runtime_error("Too few parameters for PDF:Exponential. One (1) required.");
          }
          else
          {
            fn_cdf = [GOF](FP_t p)
            {
              boost::math::exponential_distribution exponential(GOF.parameters[0]);
              return boost::math::cdf(exponential, p);
            };
          }
          break;
        }
        case PDF_WEIBULL:
        {
          if (GOF.parameters.size() < 2)
          {
            throw std::runtime_error("Too few parameters for PDF:Weibull. Two (2) required.");
          }
          else
          {
            fn_cdf = [GOF](FP_t p)
            {
              boost::math::weibull_distribution weibull(GOF.parameters[0], GOF.parameters[1]);
              return boost::math::cdf(weibull, p);
            };
          }
          break;
        }
        case PDF_GAMMA:
        {
          if (GOF.parameters.size() >= 2)
          {
            fn_cdf = [GOF](FP_t p)
            {
              boost::math::weibull_distribution gamma(GOF.parameters[0], GOF.parameters[1]);
              return boost::math::cdf(gamma, p);
            };
          }
          else
          {
            throw std::runtime_error("Too few parameters for PDF:Gamma. Two (2) required.");
          }
          break;
        }
        default:
        {
          throw std::runtime_error("Invalid PDF function");
          break;
        };
      }

      std::valarray<T> Fx(X_.size());

        /* Calculate the values.
         * Fx = F(x) where F(x) = CDF to be tested. (PDF_NORMAL etc)
         */

      for (indx = 0; indx < N; indx++)
      {
        Fx[indx] = fn_cdf(X_[indx]);
      }

      std::cout << "Fx {" << Fx[0];
      for (indx = 1; indx < N; indx++)
      {
        std::cout << ", " << Fx[indx];
      }
      std::cout << "}" << std::endl;

        // Perform the analysis.

      std::size_t N = X.size();
      FP_t A = 0;

      for (indx = 0; indx < N; indx++)
      {
        std::size_t i = indx + 1;
        A += (2 * i - 1) * (std::log(Fx[indx]) + std::log(1 - Fx[Fx.size() - i]));
        std::cout << "i: " << i << " A: " << A << std::endl;
      }

      A /= static_cast<FP_t>(N);
      A = -static_cast<FP_t>(N) - A;

      std::cout << "A: " << A << std::endl;
      std::cout << "N: " << N << std::endl;

      FP_t cv;
      FP_t AD;
      FP_t pvalue;

      switch (GOF.PDF)
      {
        case PDF_NORMAL:
        {
          AD = A * (1 + 0.75 / N + 2.25 / MCL::pow2(N));

          if (AD <= 0.2)
          {
            pvalue = 1 - std::exp(-13.436 + 101.14 * AD - 223.73 * MCL::pow2(AD));
          }
          else if (AD <= 0.34)
          {
            pvalue = 1 - std::exp(-8.318 + 42.796 * AD - 59.938 * MCL::pow2(AD));
          }
          else if (AD <= 0.6)
          {
            pvalue = std::exp(0.9177 - 4.279 * AD - 1.38 * MCL::pow2(AD));
          }
          else
          {
            std::cout << "pValue Check" << std::endl;
            pvalue = std::exp(1.2937 - 5.709 * AD + 0.0186 * MCL::pow2(AD));
          }

          if (criticalValues_normal_a.contains(GOF.alpha))
          {
            cv = criticalValues_normal_a.at(GOF.alpha) * (1 - (criticalValues_normal_b.at(GOF.alpha) / N) -
                      (criticalValues_normal_d.at(GOF.alpha) / MCL::pow2(N)));

            std::cout << "CV: " << cv << std::endl;
          }
          else
          {
            std::runtime_error("Invalid alpha value given");
          }
          break;
        }
        case PDF_WEIBULL:
        {
          AD = A * (1 + (0.2 / std::sqrt(N)));
          if (criticalValues_weibull.contains(GOF.alpha))
          {
            cv = criticalValues_weibull.at(GOF.alpha);
          }
          else
          {
            std::runtime_error("Invalid alpha value given");
          }
          break;
        }
        case PDF_EXPONENTIAL:
        {
          AD = A * (1 + (0.6 / N));
          if (criticalValues_exponential.contains(GOF.alpha))
          {
            cv = criticalValues_exponential.at(GOF.alpha);
          }
          else
          {
            std::runtime_error("Invalid alpha value given");
          }
          break;
        }
        case PDF_GAMMA:
        {
          if (GOF.parameters[0] <  2)
          {
            AD = A * (1 + (0.6 / N));
          }
          else
          {
            AD = A * (1 + ((0.2 + 0.3 / GOF.parameters[0]) / N));
          };
          if (GOF.parameters[0] == 1)
          {
            if (criticalValues_gamma_1.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_1.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] == 2)
          {
            if (criticalValues_gamma_2.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_2.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] == 3)
          {
            if (criticalValues_gamma_3.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_3.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] == 4)
          {
            if (criticalValues_gamma_4.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_4.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] == 5)
          {
            if (criticalValues_gamma_5.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_5.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] == 6)
          {
            if (criticalValues_gamma_6.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_6.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] <= 8)
          {
            if (criticalValues_gamma_8.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_8.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] <= 10)
          {
            if (criticalValues_gamma_10.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_10.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] <= 12)
          {
            if (criticalValues_gamma_12.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_12.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] <= 15)
          {
            if (criticalValues_gamma_15.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_15.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else if (GOF.parameters[0] <= 20)
          {
            if (criticalValues_gamma_20.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_20.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          else
          {
            if (criticalValues_gamma_gt.contains(GOF.alpha))
            {
              cv = criticalValues_gamma_gt.at(GOF.alpha);
            }
            else
            {
              std::runtime_error("Invalid alpha value given");
            }
          }
          break;
        };
        default:
        {
          throw std::runtime_error("Invalid PDF function");
          break;
        };
      }
      std::cout << "AD: " << AD << std::endl;
      std::cout << "CV: " << cv << std::endl;
      std::cout << "P: " << pvalue << std::endl;

      if (pvalue < cv)
      {
          // Reject the H0

        GOF.H0 = false;
      }
      else
      {
          // Accept H0

        GOF.H0 = true;
      }

    };


  }


}

#endif // ANDERSONDARLING_HPP
