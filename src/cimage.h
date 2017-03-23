#pragma once

#include <cstddef>
#include <string>


class Cimage
{
protected:
    unsigned char * _data;
    size_t _width;
    size_t _height;

public:
    Cimage(size_t width, size_t height);
    Cimage(unsigned char * data, size_t width, size_t height);
    virtual ~Cimage();

public:
    unsigned char * const data() const;
    size_t width() const;
    size_t height() const;
    static size_t how_many_bytes(size_t width, size_t height);
    virtual void info();
};
