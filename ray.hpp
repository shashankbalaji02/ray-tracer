#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

struct ray {
    point3 origin;
    vec3 direction;
    constexpr ray() : origin{}, direction{} {}
    constexpr ray(const vec3& ori, const vec3& dir) : origin{ori}, direction{dir} {}
    constexpr ray(const vec3& dir) : origin{}, direction{dir} {}
    constexpr vec3 at(const double t) const {
        return origin + t*direction;
    }
};

#endif