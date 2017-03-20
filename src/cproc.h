#pragma once

#include "cimage.h"


class Cproc
{
public:
    void run(Cimage & image);
protected:
    void mt_run(Cimage & image);
};
