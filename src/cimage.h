#pragma once

#include <cstddef>


class Cimage
{
protected:
    size_t _width;
    size_t _height;

public:
    Cimage(size_t width, size_t height);
    virtual ~Cimage();

public:
    size_t width();
    size_t height();
    static size_t how_many_bytes(size_t width, size_t height);
};
