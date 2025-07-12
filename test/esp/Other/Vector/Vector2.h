#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

struct Vector2 {
    float X;
    float Y;

    Vector2() {
        this->X = 0;
        this->Y = 0;
    }

    Vector2(float x, float y) {
        this->X = x;
        this->Y = y;
    }

    static Vector2 Zero() {
        return Vector2(0.0f, 0.0f);
    }

    static float Distance(Vector2 a, Vector2 b) {
        Vector2 vector = Vector2(a.X - b.X, a.Y - b.Y);
        return sqrt((vector.X * vector.X) + (vector.Y * vector.Y));
    }

    bool operator!=(const Vector2 &src) const {
        return (src.X != X) || (src.Y != Y);
    }

    Vector2 &operator+=(const Vector2 &v) {
        X += v.X;
        Y += v.Y;
        return *this;
    }

    Vector2 &operator-=(const Vector2 &v) {
        X -= v.X;
        Y -= v.Y;
        return *this;
    }
};