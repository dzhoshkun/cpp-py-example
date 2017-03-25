#include <chrono>
#include <iostream>
#include "proc.h"


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
