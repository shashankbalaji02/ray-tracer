#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstddef>
#include <array>
#include "pixel.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class camera {
public:
    constexpr camera(const double vw, const double ratio, const double f)
        : viewport_width{vw},
          viewport_height{vw/ratio},
          aspect_ratio{ratio},
          focal_length{f} {}
    template <std::size_t width, std::size_t height>
    /*constexpr*/ auto render(color get_color(const ray&)) const {
        std::array<std::array<pixel, width>, height> buffer{};
        for (std::size_t y = 0; y < height; y++)
            for (std::size_t x = 0; x < width; x++) {
                buffer[y][x] = to_pixel(get_color(ray{vec3{-viewport_width/2 + (x*viewport_width)/width,
                                                           -viewport_height/2 + (y*viewport_height)/height,
                                                           focal_length}}));
            }
        return buffer;
    }
private:
    const double viewport_width;
    const double viewport_height;
    const double aspect_ratio;
    const double focal_length;
};

#endif