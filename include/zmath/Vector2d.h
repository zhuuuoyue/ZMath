#pragma once

#include "ZMathExports.h"

#include <xutility>
#include <cassert>


namespace zmath
{
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

        Vector2d& Set(double x, double y)
        {
            m_xy[X_INDEX] = x;
            m_xy[Y_INDEX] = y;
            return *this;
        }

        double operator[](std::size_t index) const
        {
            assert(index < DIMENSIONS);
            return m_xy[index];
        }

        double& operator[](std::size_t index)
        {
            assert(index < DIMENSIONS);
            return m_xy[index];
        }

    public:

        Vector2d operator+() const
        {
            return *this;
        }

        Vector2d operator-() const
        {
            return Vector2d{ -m_xy[X_INDEX], -m_xy[Y_INDEX] };
        }

        Vector2d operator+(const Vector2d& right) const
        {
            return Vector2d{ X() + right.X(), Y() + right.Y() };
        }

        Vector2d& operator+=(const Vector2d& right)
        {
            m_xy[X_INDEX] += right[X_INDEX];
            m_xy[Y_INDEX] += right[Y_INDEX];
            return *this;
        }

        Vector2d operator-(const Vector2d& right) const
        {
            return Vector2d{ X() - right.X(), Y() - right.Y() };
        }

        Vector2d& operator-=(const Vector2d& right)
        {
            m_xy[X_INDEX] -= right[X_INDEX];
            m_xy[Y_INDEX] -= right[Y_INDEX];
            return *this;
        }

        Vector2d operator*(double k) const
        {
            return Vector2d{ k * X(), k * Y() };
        }

        Vector2d& operator*=(double k)
        {
            m_xy[X_INDEX] *= k;
            m_xy[Y_INDEX] *= k;
            return *this;
        }

        Vector2d operator/(double k) const
        {
            assert(!ZMathUtils::IsZero(k));
            return Vector2d{ X() / k, Y() / k };
        }

        Vector2d& operator/=(double k)
        {
            m_xy[X_INDEX] /= k;
            m_xy[Y_INDEX] /= k;
            return *this;
        }

    private:

        enum Index
        {
            X_INDEX = 0,
            Y_INDEX = 1,
            DIMENSIONS = 2
        };

        double m_xy[2]{ 0, 0 };
    };
}

zmath::Vector2d operator*(double k, const zmath::Vector2d& vec)
{
    return zmath::Vector2d{ k * vec.X(), k * vec.Y() };
}
