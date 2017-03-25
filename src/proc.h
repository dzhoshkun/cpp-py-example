#pragma once


#include <thread>
#include "bitmap.h"


class Cproc
{
protected:
    std::thread _thread;
    bool _running;
public:
    Cproc();
    ~Cproc();
public:
    void start(Bitmap & image);
    void stop();
protected:
    void run(Bitmap & image);
};
