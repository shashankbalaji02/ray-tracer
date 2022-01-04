#include <iostream>
#include <cstddef>
#include <array>
#include <cmath>
#include "vec3.hpp"
#include "pixel.hpp"
#include "utility.hpp"
#include "camera.hpp"

constexpr double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin - center;
    auto a = dot(r.direction, r.direction);
    auto b = 2.0 * dot(oc, r.direction);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - std::sqrt(discriminant) ) / (2.0*a);
    }
}

constexpr color get_color(const ray& r) {
    auto t = hit_sphere(point3(0, 0, 1.5), 0.5, r);
    if (t > 0.0) {
        vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
        return 0.5*color(N.x + 1, N.y + 1, N.z + 1);
    }
    vec3 unit_direction = unit_vector(r.direction);
    t = 0.5*(unit_direction.y + 1.0);
    return (1 - t)*color(1, 1, 1) + t*color(0.5, 0.7, 1);
}

int main() {
    constexpr std::size_t width = 1024;
    constexpr double aspect_ratio = 16.0/9;
    constexpr std::size_t height = static_cast<std::size_t>(width/aspect_ratio);
    constexpr camera c{2*aspect_ratio, aspect_ratio, 1};
    /*constexpr*/ auto buffer = c.render<width, height>(get_color);
    std::cout << "P3\n" << width << ' ' << height << "\n255\n";
    print_buffer(std::cout, buffer);
    std::clog << "Done\n";
}