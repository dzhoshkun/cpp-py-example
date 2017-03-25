#include "except.h"


FileError::FileError()
    : std::exception()
{
    // nop
}


FileError::~FileError() noexcept
{
    // nop
}
