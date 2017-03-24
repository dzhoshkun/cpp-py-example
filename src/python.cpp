#include <boost/python.hpp>
#include <boost/python/exception_translator.hpp>
#include <boost/python/numpy.hpp>
#include "cimage.h"
#include "cproc.h"
#include "gil.h"
#include "except.h"
#include "bitmap.h"


using namespace boost::python;


class BitmapWrapper : public Bitmap
                      , public wrapper<Bitmap>
{
    public:
        BitmapWrapper(std::string filepath)
            : Bitmap(filepath)
        {
            // nop
        }

        numpy::ndarray data_as_ndarray() const
        {
            tuple shape, strides;
            numpy::dtype data_type = numpy::dtype::get_builtin<uint8_t>();
            shape = make_tuple(_height,
                               _width,
                               3);
            strides = make_tuple(_width * 3 * sizeof(uint8_t),
                                 3 * sizeof(uint8_t),
                                 sizeof(uint8_t));
            return numpy::from_data(_data,
                                    data_type,
                                    shape,
                                    strides,
                                    object());
        }
};

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
};


void translate_FileError(FileError const & e)
{
    PyErr_SetString(PyExc_OSError, "FileError");
}


BOOST_PYTHON_MODULE(pymycpp)
{
    PyEval_InitThreads();

    numpy::initialize();

    register_exception_translator<FileError>(&translate_FileError);

    class_<CimageWrapper, boost::noncopyable>(
            "Cimage", init<size_t, size_t>())
        .def("width", &CimageWrapper::width)
        .def("height", &CimageWrapper::height)
        .def("how_many_bytes", &CimageWrapper::how_many_bytes)
        .staticmethod("how_many_bytes")
        .def("info", &CimageWrapper::info)
        ;

    class_<Cproc, boost::noncopyable>(
            "Cproc", init<>())
        .def("run", &Cproc::run)
        .def("stop", &Cproc::stop)
        ;

    class_<BitmapWrapper, boost::noncopyable>(
            "Bitmap", init<std::string>())
        .def("get_width", &BitmapWrapper::get_width)
        .def("get_height", &BitmapWrapper::get_height)
        .def("save", &BitmapWrapper::save)
        .def("data", &BitmapWrapper::data_as_ndarray)
        ;
}
