#include <chrono>
#include <iostream>
#include "proc.h"


size_t Proc::_version = 1703;


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


Proc::Proc()
    : _running(false)
{
    // nop
}


Proc::~Proc()
{
    stop();
}


void Proc::start(Bitmap & image)
{
    _running = true;
    _thread = std::thread(&Proc::run, this, std::ref(image));
}


void Proc::stop()
{
    _running = false;
    if (_thread.joinable())
        _thread.join();
}


size_t Proc::get_version()
{
    return _version;
}


void Proc::run(Bitmap & image)
{
    size_t count = 0;

    while (_running)
    {
        std::cout << ++count << ". iteration: "
                  << image.info() << std::endl;
        std::this_thread::sleep_for(
                std::chrono::milliseconds(500));
    }
}
