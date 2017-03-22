#pragma once
#include <stdexcept>


class FileNotFound : public std::exception
{
public:
    FileNotFound();
    virtual ~FileNotFound() noexcept;
};
