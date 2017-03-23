#include "bitmap.h"
#include "except.h"


std::string timestamp(std::string filepath);

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
    std::string filepath_ts = timestamp(_filepath);
    FILE * fptr = fopen(filepath_ts.c_str(), "wb");
    if (fptr == nullptr)
        throw FileError();

    unsigned char bmp_header[54] = {'B','M',
                                    0, 0, 0, 0,
                                    0, 0,
                                    0, 0,
                                    54, 0, 0, 0,
                                    40, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    1, 0,
                                    24, 0};

    size_t num_bytes = 3 * _width * _height;
    *(int *)&bmp_header[2] = (int)(54 + num_bytes);
    *(int *)&bmp_header[18] = (int) _width;
    *(int *)&bmp_header[22] = (int) _height;

    fwrite(bmp_header, sizeof(uint8_t), 54, fptr);

    fwrite(_data, sizeof(uint8_t), num_bytes, fptr);

    fclose(fptr);

    return filepath_ts;
}

std::string timestamp(std::string filepath)
{
    // TODO
    return "";
}
