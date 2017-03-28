#include <boost/python.hpp>
#include <boost/python/exception_translator.hpp>
#include "except.h"


using namespace boost::python;


void translate_FileError(FileError const & e)
{
    PyErr_SetString(PyExc_OSError, "FileError translated");
}


BOOST_PYTHON_MODULE(pymycpp)
{
    register_exception_translator<FileError>(&translate_FileError);
}
