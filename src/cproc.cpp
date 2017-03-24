#include <chrono>
#include "cproc.h"


Cproc::Cproc()
    : _running(false)
{

}

Cproc::~Cproc()
{
    stop();
}

void Cproc::start(Cimage & image)
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

void Cproc::run(Cimage & image)
{
    size_t count = 0;
    while (_running)
    {
        printf("%lu. iteration: ", ++count);
        fflush(stdout);
        image.info();
        std::this_thread::sleep_for(
                std::chrono::milliseconds(500));
    }
}
