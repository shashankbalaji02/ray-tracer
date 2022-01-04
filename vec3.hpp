#ifndef VEC3_HPP
#define VEC3_HPP

#include <cstddef>
#include <iostream>
#include <cmath>

struct vec3 {
    constexpr vec3() : x{0}, y{0}, z{0} {}
    constexpr vec3(const double a, const double b, const double c) : x{a}, y{b}, z{c} {}
    constexpr double length_squared() const {
        return x*x + y*y + z*z;
    }
    constexpr double length() const {
        return std::sqrt(length_squared());
    }
    constexpr vec3 operator-() const {
        return vec3{-x, -y, -z};
    }
    constexpr vec3& operator+=(const vec3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    constexpr vec3& operator-=(const vec3& v) {
        return *this += -v;
    }
    constexpr vec3& operator*=(const double s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    constexpr vec3& operator/=(const double s) {
        return *this *= 1/s;
    }
    friend constexpr vec3 operator*(const vec3&, const double);
    friend constexpr vec3 operator*(const double, const vec3&);
    friend constexpr vec3 operator/(const vec3&, const double);
    friend constexpr vec3 operator+(const vec3&, const vec3&);
    friend constexpr vec3 operator-(const vec3&, const vec3&);
    friend std::ostream& operator<<(std::ostream&, const vec3&);
    friend std::istream& operator>>(std::istream&, vec3&);
    friend constexpr double dot(const vec3&, const vec3&);
    friend constexpr vec3 cross(const vec3&, const vec3&);
    friend constexpr vec3 unit_vector(const vec3&);
    union {
        double x;
        double r;
    };
    union {
        double y;
        double g;
    };
    union {
        double z;
        double b;
    };
};

typedef vec3 point3;
typedef vec3 color;

constexpr vec3 operator*(const vec3& v, const double s) {
    return vec3{v.x*s, v.y*s, v.z*s};
}
constexpr vec3 operator*(const double s, const vec3& v) {
    return v*s;
}
constexpr vec3 operator/(const vec3& v, const double s) {
    return v*(1/s);
}
constexpr vec3 operator+(const vec3& v1, const vec3& v2) {
    return vec3{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}
constexpr vec3 operator-(const vec3& v1, const vec3& v2) {
    return v1 + -v2;
}
std::ostream& operator<<(std::ostream& out, const vec3& v) {
    out << '(' << v.x << ", " << v.y << ", " << v.z << ')';
    return out;
}
std::istream& operator>>(std::istream& in, vec3& v) {
    double x = 0, y = 0, z = 0;
    in >> x >> y >> z;
    v = vec3{x, y, z};
    return in;
}
constexpr double dot(const vec3& v1, const vec3& v2) {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}
constexpr vec3 cross(const vec3& v1, const vec3& v2) {
    return vec3(v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x);
}
constexpr vec3 unit_vector(const vec3& v) {
    return v/v.length();
}

#endif