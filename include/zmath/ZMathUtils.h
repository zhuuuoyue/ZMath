#pragma once

#include "ZMathConsts.h"


namespace zmath
{
    struct ZMathUtils
    {
        static bool LessThan(double left, double right, double tol = ZMathConsts::TOL_DOUBLE)
        {
            return left < (right - tol);
        }

        static bool GreaterThan(double left, double right, double tol = ZMathConsts::TOL_DOUBLE)
        {
            return LessThan(right, left, tol);
        }

        static bool LessThanOrEqualTo(double left, double right, double tol = ZMathConsts::TOL_DOUBLE)
        {
            return !LessThan(right, left, tol);
        }

        static bool GreaterThanOrEqualTo(double left, double right, double tol = ZMathConsts::TOL_DOUBLE)
        {
            return !LessThan(left, right, tol);
        }

        static bool EqualTo(double left, double right, double tol = ZMathConsts::TOL_DOUBLE)
        {
            return !LessThan(left, right, tol) && !LessThan(right, left, tol);
        }

        static bool NotEqualTo(double left, double right, double tol = ZMathConsts::TOL_DOUBLE)
        {
            return LessThan(left, right, tol) || LessThan(right, left, tol);
        }

        static bool IsZero(double value, double tol = ZMathConsts::TOL_DOUBLE)
        {
            return EqualTo(value, tol);
        }

        static bool IsPositive(double value, double tol = ZMathConsts::TOL_DOUBLE)
        {
            return LessThan(0, value, tol);
        }

        static bool IsNegative(double value, double tol = ZMathConsts::TOL_DOUBLE)
        {
            return LessThan(value, 0, tol);
        }
    };

    struct LessThanPredictor
    {
        double tolerance{ ZMathConsts::TOL_DOUBLE };

        explicit LessThanPredictor(double tol = ZMathConsts::TOL_DOUBLE)
            : tolerance{ tol }
        {
        }

        bool operator()(double left, double right) const
        {
            return ZMathUtils::LessThan(left, right, tolerance);
        }
    };

    struct LessThanOrEqualToPredictor
    {
        double tolerance{ ZMathConsts::TOL_DOUBLE };

        explicit LessThanOrEqualToPredictor(double tol = ZMathConsts::TOL_DOUBLE)
            : tolerance{ tol }
        {
        }

        bool operator()(double left, double right) const
        {
            return ZMathUtils::LessThanOrEqualTo(left, right, tolerance);
        }
    };

    struct GreaterThanPredictor
    {
        double tolerance{ ZMathConsts::TOL_DOUBLE };

        explicit GreaterThanPredictor(double tol = ZMathConsts::TOL_DOUBLE)
            : tolerance{ tol }
        {
        }

        bool operator()(double left, double right) const
        {
            return ZMathUtils::GreaterThan(left, right, tolerance);
        }
    };

    struct GreaterThanOrEqualToPredictor
    {
        double tolerance{ ZMathConsts::TOL_DOUBLE };

        explicit GreaterThanOrEqualToPredictor(double tol = ZMathConsts::TOL_DOUBLE)
            : tolerance{ tol }
        {
        }

        bool operator()(double left, double right) const
        {
            return ZMathUtils::GreaterThanOrEqualTo(left, right, tolerance);
        }
    };

    struct EqualToPredictor
    {
        double tolerance{ ZMathConsts::TOL_DOUBLE };

        explicit EqualToPredictor(double tol = ZMathConsts::TOL_DOUBLE)
            : tolerance{ tol }
        {
        }

        bool operator()(double left, double right) const
        {
            return ZMathUtils::EqualTo(left, right, tolerance);
        }
    };

    struct NotEqualToPredictor
    {
        double tolerance{ ZMathConsts::TOL_DOUBLE };

        explicit NotEqualToPredictor(double tol = ZMathConsts::TOL_DOUBLE)
            : tolerance{ tol }
        {
        }

        bool operator()(double left, double right) const
        {
            return ZMathUtils::NotEqualTo(left, right, tolerance);
        }
    };
}
