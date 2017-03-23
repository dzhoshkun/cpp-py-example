#include <boost/python.hpp>
#include <boost/python/exception_translator.hpp>
#include <boost/python/numpy.hpp>
#include "cimage.h"
#include "cproc.h"
#include "gil.h"
#include "except.h"
#include "file.h"


using namespace boost::python;


class CimageWrapper
    : public Cimage
    , public wrapper<Cimage>
{
public:
    CimageWrapper(size_t width, size_t height)
        : Cimage(width, height)
    {

    }

public:
    void info()
    {
        ScopedPythonGILLock gil_lock;
        override f = this->get_override("info");
        if (f)
            f();
        else
            Cimage::info();
    }

    numpy::ndarray data_as_ndarray() const
    {
        tuple shape, strides;
        numpy::dtype data_type = numpy::dtype::get_builtin<uint8_t>();
        shape = make_tuple(this->height(), this->width(), 3);
        strides = make_tuple(this->width() * 3 * sizeof(uint8_t),
                             3 * sizeof(uint8_t),
                             sizeof(uint8_t));
        return numpy::from_data(this->data(), data_type, shape, strides,
                                object());
    }
};


void translate_FileError(FileError const & e)
{
    PyErr_SetString(PyExc_OSError, "FileError");
}


BOOST_PYTHON_MODULE(pymycpp)
{
    PyEval_InitThreads();

    register_exception_translator<FileError>(&translate_FileError);
    class_<CimageWrapper, boost::noncopyable>(
            "Cimage", init<size_t, size_t>())
        .def("width", &CimageWrapper::width)
        .def("height", &CimageWrapper::height)
        .def("how_many_bytes", &CimageWrapper::how_many_bytes)
        .staticmethod("how_many_bytes")
        .def("info", &CimageWrapper::info)
        .def("data", &CimageWrapper::data_as_ndarray)
        ;

    class_<Cproc, boost::noncopyable>(
            "Cproc", init<>())
        .def("run", &Cproc::run)
        .def("stop", &Cproc::stop)
        ;

    class_<File>("File", no_init)
        .def("read", &File::read,
             return_value_policy<reference_existing_object>())
        .staticmethod("read")
        .def("write", &File::write)
        .staticmethod("write")
        ;
}
