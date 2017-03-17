#pragma once

#include <cstddef>


class Cimage
{
protected:
    unsigned char * _data;
    size_t _width;
    size_t _height;

public:
    Cimage(unsigned char * data, size_t width, size_t height);
    virtual ~Cimage();

public:
    unsigned char * const data();
    size_t width();
    size_t height();
};
