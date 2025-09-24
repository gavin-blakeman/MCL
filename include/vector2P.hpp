#ifndef MCL_VECTOR2P_HPP
#define MCL_VECTOR2P_HPP

#include <cmath>

#include "constants.h"
#include "point2D.hpp"

namespace MCL
{

  template<typename T>
  class vector2P_t
  {
  public:
    using point_t = point2D<T>;

    inline vector2P_t() = default;
    inline vector2P_t(point_t P1, point_t P2) : p1(P1), p2(P2) {};
    vector2P_t(vector2P_t const &) = default;
    vector2P_t(vector2P_t &&) = default;
    inline ~vector2P_t() = default;

    vector2P_t &operator=(vector2P_t const &) = default;
    vector2P_t &operator=(vector2P_t &&) = default;

    point_t const &P1() const noexcept { return p1; }
    point_t &P1() noexcept { return p1; }
    point_t const &P2() const noexcept { return p2; }
    point_t &P2() noexcept { return p2; }

    T angle()
    {
      T distX, distY, rad, angle;

      distX = p2.X() - p1.X();
      distY = p2.Y() - p1.Y();
      rad = sqrt(distX * distX + distY * distY);

      if (fabs(rad) >= zeroTolerance)
      {
        if (fabs(distX) > zeroTolerance)
        {
          angle = acos(distX / rad);
        }
        else
        {
          angle = asin(distY / rad);
        }

        // Correct the angle.

        if (distX > 0)
        {
          if (distY > 0)
          {
            // No change to the angle.
          }
          else
          {
            angle += PI + PI_DIV_2;
          }
        }
        else
        {
          if (distY > 0)
          {
            angle += PI_DIV_2;
          }
          else
          {
            angle += PI;
          }
        }
      }
      else
      {
        angle = 0;   // Same point???
      }

      return angle;

    }


  protected:
  private:
    point2D<T> p1;
    point2D<T> p2;
    T zeroTolerance = 1e-6;
  };

}

#endif
