#ifndef VEC3_HPP
#define VEC3_HPP

#include <cstddef>
#include <iostream>
#include <cmath>

struct vec3 {
    constexpr vec3() : e{0, 0, 0} {}
    constexpr vec3(const double x, const double y, const double z) : e{x, y, z} {}
    constexpr double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
    constexpr double length() const {
        return std::sqrt(length_squared());
    }
    constexpr double& operator[](const std::size_t i) {
        return e[i];
    }
    constexpr const double& operator[](const std::size_t i) const {
        return e[i];
    }
    constexpr vec3 operator-() const {
        return vec3{-e[0], -e[1], -e[2]};
    }
    constexpr vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }
    constexpr vec3& operator-=(const vec3& v) {
        return *this += -v;
    }
    constexpr vec3& operator*=(const double s) {
        e[0] *= s;
        e[1] *= s;
        e[2] *= s;
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
private:
    double e[3];
};

typedef vec3 point3;
typedef vec3 color;

constexpr vec3 operator*(const vec3& v, const double s) {
    return vec3{v.e[0]*s, v.e[1]*s, v.e[2]*s};
}
constexpr vec3 operator*(const double s, const vec3& v) {
    return v*s;
}
constexpr vec3 operator/(const vec3& v, const double s) {
    return v*(1/s);
}
constexpr vec3 operator+(const vec3& v1, const vec3& v2) {
    return vec3{v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]};
}
constexpr vec3 operator-(const vec3& v1, const vec3& v2) {
    return v1 + -v2;
}
std::ostream& operator<<(std::ostream& out, const vec3& v) {
    out << '(' << v.e[0] << ", " << v.e[1] << ", " << v.e[2] << ')';
    return out;
}
std::istream& operator>>(std::istream& in, vec3& v) {
    double x = 0, y = 0, z = 0;
    in >> x >> y >> z;
    v = vec3{x, y, z};
    return in;
}
constexpr double dot(const vec3& v1, const vec3& v2) {
    return v1.e[0]*v2.e[0] + v1.e[1]*v2.e[1] + v1.e[2]*v2.e[2];
}
constexpr vec3 cross(const vec3& v1, const vec3& v2) {
    return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
                v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
                v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}
constexpr vec3 unit_vector(const vec3& v) {
    return v/v.length();
}

#endif