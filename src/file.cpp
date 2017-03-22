#include "file.h"
#include "except.h"


unsigned char bmp_header[54];

Cimage * File::read(std::string filepath)
{
    FILE * fptr = fopen(filepath.c_str(), "rb");
    if (fptr == nullptr)
        throw FileNotFound();

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
    // TODO
}
