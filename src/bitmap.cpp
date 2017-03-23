#include "bitmap.h"
#include "except.h"


Bitmap::Bitmap(std::string filepath)
    : _filepath(filepath)
      , _data(nullptr)
      , _width(0)
      , _height(0)
{
    FILE * fptr = fopen(_filepath.c_str(), "rb");
    if (fptr == nullptr)
        throw FileError();

    uint8_t bmp_header[54];
    fread(bmp_header, sizeof(uint8_t), 54, fptr);
    _width = *(int *)&bmp_header[18];
    _height = *(int *)&bmp_header[22];

    size_t num_bytes = 3 * _width * _height;
    _data = new uint8_t[num_bytes];
    fread(_data, sizeof(uint8_t), num_bytes, fptr);

    fclose(fptr);
}

Bitmap::~Bitmap()
{
    save();
    if (_data != nullptr)
        delete [] _data;
}

uint8_t * const Bitmap::get_data() const
{
    return _data;
}

size_t Bitmap::get_width() const
{
    return _width;
}

size_t Bitmap::get_height() const
{
    return _height;
}

std::string Bitmap::save() const
{
    // TODO
    return "";
}
