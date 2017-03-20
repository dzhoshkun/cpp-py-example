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
};
