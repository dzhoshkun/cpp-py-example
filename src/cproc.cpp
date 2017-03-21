#include <thread>
#include <chrono>
#include "cproc.h"


void Cproc::run(Cimage & image)
{
    std::thread thr(&Cproc::mt_run, this, std::ref(image));
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    thr.join();
}

void Cproc::mt_run(Cimage & image)
{
    image.info();
}
