#pragma once

#include "ZMathNamespace.h"
#include "ZMathExports.h"


ZMATH_NAMESPACE_BEGIN

class ZMATH_API Vector2d
{
public:

    static const Vector2d ZERO;

    static const Vector2d X_UNIT;

    static const Vector2d Y_UNIT;

    explicit Vector2d() {}

    explicit Vector2d(double x, double y)
        : m_xy{ x, y }
    {
    }

    Vector2d(const Vector2d& other)
        : m_xy{ other.X(), other.Y() }
    {
    }

    Vector2d& operator=(const Vector2d& right)
    {
        m_xy[X_INDEX] = right.X();
        m_xy[Y_INDEX] = right.Y();
        return *this;
    }

    double X() const { return m_xy[X_INDEX]; }

    Vector2d& SetX(double value)
    {
        m_xy[X_INDEX] = value;
        return *this;
    }

    double Y() const { return m_xy[Y_INDEX]; }

    Vector2d& SetY(double value)
    {
        m_xy[Y_INDEX] = value;
        return *this;
    }

private:

    enum Index
    {
        X_INDEX = 0,
        Y_INDEX = 1
    };

    double m_xy[2]{ 0, 0 };
};

ZMATH_NAMESPACE_END
