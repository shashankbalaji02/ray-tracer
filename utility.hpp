#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstddef>
#include <iostream>
#include "vec3.hpp"
#include "pixel.hpp"

constexpr pixel to_pixel(const vec3& c) {
    return {static_cast<unsigned char>(static_cast<int>(255.999*c[0])),
            static_cast<unsigned char>(static_cast<int>(255.999*c[1])),
            static_cast<unsigned char>(static_cast<int>(255.999*c[2]))};
}

constexpr pixel to_pixel(const double r, const double g, const double b) {
    return {static_cast<unsigned char>(static_cast<int>(255.999*r)),
            static_cast<unsigned char>(static_cast<int>(255.999*g)),
            static_cast<unsigned char>(static_cast<int>(255.999*b))};
}

template <std::size_t width, std::size_t height>
void print_buffer(std::ostream& out, const std::array<std::array<pixel, width>, height>& buffer) {
    for (std::size_t j = 0; j < height; j++) {
        for (std::size_t i = 0; i < width; i++)
            out << buffer[j][i] << ' ';
        out << '\n';
    }
}

#endif