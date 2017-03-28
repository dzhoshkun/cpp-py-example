#include "proc.h"


void grad(uint8_t * const data,
          size_t width, size_t height)
{
    size_t pixel_index;
    float i_slice, j_slice;
    for (size_t j = 0; j < height; j++)
    {
        j_slice = static_cast<float>(j + 1);
        for (size_t i = 0; i < width; i++)
        {
            pixel_index = j * width * 3 + i;
            i_slice = static_cast<float>(i + 1);
            data[pixel_index] = static_cast<uint8_t>(i_slice / width * 255);
            data[pixel_index + 1] = 255;
            data[pixel_index + 2] = static_cast<uint8_t>(j_slice / height * 255);
        }
    }
}
