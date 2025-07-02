#ifndef VEC2_H
#define VEC2_H

#include <cstdint>
#include <cmath>

namespace vec2 
{

template <typename T>
class Vec2 
{

public:

    T x;
    T y;

    static Vec2<T> create(T x, T y) { return Vec2<T>{x, y}; }

    static Vec2<T> zero() { return Vec2<T> { 0, 0 }; }

    static Vec2<T> add(Vec2<T> a, Vec2<T> b) { return Vec2<T>{ static_cast<T>(a.x + b.x), static_cast<T>(a.y + b.y) }; }
    static Vec2<T> subtract(Vec2<T> a, Vec2<T> b) { return Vec2<T>{ static_cast<T>(a.x - b.x), static_cast<T>(a.y - b.y) }; }
    static Vec2<T> multiply(Vec2<T> a, Vec2<T> b) { return Vec2<T>{ static_cast<T>(a.x * b.x), static_cast<T>(a.y * b.y) }; }
    static Vec2<T> divide(Vec2<T> a, Vec2<T> b) { return Vec2<T>{ static_cast<T>(a.x / b.x), static_cast<T>(a.y / b.y) }; }

    static T cross(Vec2<T> a, Vec2<T> b) { static_cast<T>(a.x * b.y - a.y * b.x); }
    static Vec2<T> scale(Vec2<T> vector, double factor) { return Vec2<T>{ static_cast<T>(vector.x * factor), static_cast<T>(vector.y * factor) }; }

    static double length(Vec2<T> vector) { return std::sqrt(vector.x * vector.x + vector.y * vector.y); }
    static double distance(Vec2<T> a, Vec2<T> b) { return length(subtract(a, b)); }
    static Vec2<double> normalize(Vec2<T> vector) { return Vec2<double>{ static_cast<T>(vector.x / length()), static_cast<T>(vector.y / length()) }; }

    double length() { return std::sqrt(x * x + y * y); }

    template <typename U>
    Vec2<T> operator+(Vec2<U> const &other) const { return Vec2<T>{ static_cast<T>(x + other.x), static_cast<T>(y + other.y) }; }
    template <typename U>
    Vec2<T> operator-(Vec2<U> const &other) const { return Vec2<T>{ static_cast<T>(x - other.x), static_cast<T>(y - other.y) }; }
    template <typename U>
    Vec2<T> operator*(Vec2<U> const &other) const { return Vec2<T>{ static_cast<T>(x * other.x), static_cast<T>(y * other.y) }; }
    template <typename U>
    Vec2<T> operator/(Vec2<U> const &other) const { return Vec2<T>{ static_cast<T>(x / other.x), static_cast<T>(y / other.y) }; }

    Vec2<T> operator+(double const &factor) const { return Vec2<T>{ static_cast<T>(x + factor), static_cast<T>(y + factor) }; }
    Vec2<T> operator-(double const &factor) const { return Vec2<T>{ static_cast<T>(x - factor), static_cast<T>(y - factor) }; }
    Vec2<T> operator*(double const &factor) const { return Vec2<T>{ static_cast<T>(x * factor), static_cast<T>(y * factor) }; }
    Vec2<T> operator/(double const &factor) const { return Vec2<T>{ static_cast<T>(x / factor), static_cast<T>(y / factor) }; }

    Vec2<T> operator-() const { return Vec2<T>{ static_cast<T>(-x), static_cast<T>(-y) }; }

    template <typename U>
    Vec2<T>& operator+=(Vec2<U> const &other) { x += other.x; y += other.y; return *this; }
    template <typename U>
    Vec2<T>& operator-=(Vec2<U> const &other) { x -= other.x; y -= other.y; return *this; }
    template <typename U>
    Vec2<T>& operator*=(Vec2<U> const &other) { x *= other.x; y *= other.y; return *this; }
    template <typename U>
    Vec2<T>& operator/=(Vec2<U> const &other) { x /= other.x; y /= other.y; return *this; }

    Vec2<T>& operator+=(double const &factor) { x += factor; y += factor; return *this; }
    Vec2<T>& operator-=(double const &factor) { x -= factor; y -= factor; return *this; }
    Vec2<T>& operator*=(double const &factor) { x *= factor; y *= factor; return *this; }
    Vec2<T>& operator/=(double const &factor) { x /= factor; y /= factor; return *this; }

    bool operator==(Vec2<T> const &other) const { return x == other.x && y == other.y; }
    void operator=(Vec2<T> const &other) { x = other.x; y = other.y; }

    template <typename U>
    operator Vec2<U>() const { return { static_cast<U>(x), static_cast<U>(y) }; }
};

using vec2l = Vec2<int64_t>;
using vec2i = Vec2<int32_t>;
using vec2s = Vec2<int16_t>;
using vec2b = Vec2<int8_t>;

using vec2ul = Vec2<uint64_t>;
using vec2ui = Vec2<uint32_t>;
using vec2us = Vec2<uint16_t>;
using vec2ub = Vec2<uint8_t>;

using vec2d = Vec2<double>;
using vec2f = Vec2<float>;

}

#endif // VEC2_H
