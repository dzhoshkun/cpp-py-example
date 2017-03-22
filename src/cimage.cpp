#include "cimage.h"


Cimage::Cimage(size_t width, size_t height)
    : _width(width)
    , _height(height)
{

}

Cimage::Cimage(unsigned char * data, size_t width, size_t height)
    : _data(data)
    , _width(width)
    , _height(height)
{

}

Cimage::~Cimage()
{
    if (_data != nullptr)
        delete [] _data;
}

unsigned char * const Cimage::data()
{
    return _data;
}

size_t Cimage::width()
{
    return _width;
}

size_t Cimage::height()
{
    return _height;
}

size_t Cimage::how_many_bytes(size_t width, size_t height)
{
    return 4 * width * height;
}

void Cimage::info()
{
    printf("Cimage (C++): %lux%lu\n", _width, _height);
}
