#include "file.h"
#include "except.h"


Cimage * File::read(std::string filepath)
{
    FILE * fptr = fopen(filepath.c_str(), "rb");
    if (fptr == nullptr)
        throw FileError();

    unsigned char bmp_header[54];
    fread(bmp_header, sizeof(unsigned char), 54, fptr);
    int width = *(int *)&bmp_header[18];
    int height = *(int *)&bmp_header[22];

    size_t num_bytes = 3 * width * height;
    unsigned char * data = new unsigned char[num_bytes];
    fread(data, sizeof(unsigned char), num_bytes, fptr);

    fclose(fptr);

    return new Cimage(data, width, height);
}

void File::write(const Cimage & image, std::string filepath)
{
    FILE * fptr = fopen(filepath.c_str(), "wb");
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

    size_t num_bytes = 3 * image.width() * image.height();
    *(int *)&bmp_header[2] = (int)(54 + num_bytes);
    *(int *)&bmp_header[18] = (int) image.width();
    *(int *)&bmp_header[22] = (int) image.height();
    fwrite(bmp_header, sizeof(unsigned char), 54, fptr);

    fwrite(image.data(), sizeof(unsigned char), num_bytes, fptr);

    fclose(fptr);
}
