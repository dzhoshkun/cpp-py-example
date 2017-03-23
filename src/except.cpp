#include "except.h"


FileNotFound::FileNotFound()
    : std::exception()
{

}

FileNotFound::~FileNotFound() noexcept
{

}
