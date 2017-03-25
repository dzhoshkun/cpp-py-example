#pragma once


#include <thread>
#include "bitmap.h"


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
