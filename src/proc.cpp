#include <chrono>
#include <iostream>
#include "proc.h"


Cproc::Cproc()
    : _running(false)
{

}

Cproc::~Cproc()
{
    stop();
}

void Cproc::start(Bitmap & image)
{
    _running = true;
    _thread = std::thread(&Cproc::run, this, std::ref(image));
}

void Cproc::stop()
{
    _running = false;
    if (_thread.joinable())
        _thread.join();
}

void Cproc::run(Bitmap & image)
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
