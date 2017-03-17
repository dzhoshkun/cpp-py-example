#include "cimage.h"


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
