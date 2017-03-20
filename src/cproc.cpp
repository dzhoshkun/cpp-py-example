#include <thread>
#include "cproc.h"


void Cproc::run(Cimage & image)
{
    std::thread thr(&Cproc::mt_run, this, std::ref(image));
    thr.join();
}

void Cproc::mt_run(Cimage & image)
{
    image.info();
}
