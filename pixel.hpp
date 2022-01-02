#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>

struct pixel {
    unsigned char r = 0, g = 0, b = 0;
};

std::ostream& operator<<(std::ostream& out, const pixel& p) {
    out << +p.r << ' ' << +p.g << ' ' << +p.b;
    return out;
}

#endif