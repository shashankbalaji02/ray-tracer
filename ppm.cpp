#include <iostream>
#include <cstddef>
#include <array>
#include "vec3.hpp"
#include "pixel.hpp"
#include "utility.hpp"

constexpr color get_color(const std::size_t x, const std::size_t y, const std::size_t width, const std::size_t height) {
    return {static_cast<double>(x)/(width - 1), static_cast<double>(y)/(height - 1), 0.5};
}

template <std::size_t width, std::size_t height>
constexpr auto render() {
    std::array<std::array<pixel, width>, height> buffer{};
    for (std::size_t j = 0; j < height; j++) {
        for (std::size_t i = 0; i < width; i++) {
            buffer[j][i] = to_pixel(get_color(i, j, width, height));
        }
    }
    return buffer;
}

int main() {
    constexpr std::size_t width = 256;
    constexpr std::size_t height = 256;
    constexpr auto buffer = render<width, height>();
    std::cout << "P3\n" << width << ' ' << height << "\n255\n";
    print_buffer(std::cout, buffer);
    std::clog << "Done\n";
}