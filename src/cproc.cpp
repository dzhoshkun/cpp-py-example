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

void Cproc::run(Cimage & image)
{
    _running = true;
    _thread = std::thread(&Cproc::mt_run, this, std::ref(image));
}

void Cproc::stop()
{
    _running = false;
    _thread.join();
}

void Cproc::mt_run(Cimage & image)
{
    size_t count = 0;
    while (_running)
    {
        printf("%lu. iteration: ", ++count);
        image.info();
        std::this_thread::sleep_for(
                std::chrono::milliseconds(500));
    }
}
