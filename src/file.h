#pragma once
#include <string>
#include "cimage.h"


class File
{
public:
    static Cimage * read(std::string filepath);
    static void write(const Cimage & image, std::string filepath);
};
