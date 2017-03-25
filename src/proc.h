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
        static size_t _version;

    public:
        Proc();
        ~Proc();

    public:
        void start(Bitmap & image);
        void stop();
        static size_t get_version();

    protected:
        void run(Bitmap & image);
};
