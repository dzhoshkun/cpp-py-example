#pragma once


#include <thread>
#include "bitmap.h"


void grad(uint8_t * const data,
          size_t width, size_t height);


class Proc
{
    protected:
        std::thread _thread;
        bool _running;

    public:
        Proc();
        ~Proc();

    public:
        void start(Bitmap & image);
        void stop();

    protected:
        void run(Bitmap & image);
};
