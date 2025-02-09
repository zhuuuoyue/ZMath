#pragma once

#include "ZMathExports.h"

#include <cmath>
#include <cassert>

#include "Vector2d.h"
#include "ZMathConsts.h"
#include "ZMathUtils.h"


namespace zmath
{
    struct ZMATH_API Vector2dUtils
    {
        static double Length(const Vector2d& vec)
        {
            return std::sqrt(vec.X() * vec.X() + vec.Y() * vec.Y());
        }

        static bool IsZero(const Vector2d& vec, double tol = ZMathConsts::TOL_DOUBLE)
        {
            double len = Length(vec);
            return ZMathUtils::IsZero(len, tol);
        }

        static bool IsUnit(const Vector2d& vec, double tol = ZMathConsts::TOL_DOUBLE)
        {
            double len = Length(vec);
            return ZMathUtils::EqualTo(len, 1, tol);
        }

        static void Normalize(Vector2d& vec, double tol = ZMathConsts::TOL_DOUBLE)
        {
            assert(!IsZero(vec, tol));
            double len = Length(vec);
            vec.Set(vec.X() / len, vec.Y() / len);
        }

        static double Dot(const Vector2d& v1, const Vector2d& v2)
        {
            return v1.X() * v2.X() + v1.Y() * v2.Y();
        }

        static double CrossProduct(const Vector2d& v1, const Vector2d& v2)
        {
            return v1.X() * v2.Y() - v1.Y() * v2.X();
        }
    };
}
