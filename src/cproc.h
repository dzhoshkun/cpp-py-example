#pragma once

#include <thread>
#include "cimage.h"


class Cproc
{
protected:
    std::thread _thread;
    bool _running;
public:
    Cproc();
    ~Cproc();
public:
    void run(Cimage & image);
    void stop();
protected:
    void mt_run(Cimage & image);
};
