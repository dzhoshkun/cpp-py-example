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
    void start(Cimage & image);
    void stop();
protected:
    void run(Cimage & image);
};
