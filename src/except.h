#pragma once
#include <stdexcept>


class FileError : public std::exception
{
public:
    FileError();
    virtual ~FileError() noexcept;
};
