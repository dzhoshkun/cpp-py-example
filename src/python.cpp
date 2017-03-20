#include <boost/python.hpp>
#include "cimage.h"
#include "cproc.h"


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
        override f = this->get_override("info");
        if (f)
            f();
        else
            Cimage::info();
    }
};


class CprocWrapper
    : public Cproc
    , public wrapper<Cproc>
{
public:
    void run(Cimage & image)
    {
        Cproc::run(boost::ref(image));
    }
};


BOOST_PYTHON_MODULE(pymycpp)
{
    class_<CimageWrapper, boost::noncopyable>(
            "Cimage", init<size_t, size_t>())
        .def("width", &CimageWrapper::width)
        .def("height", &CimageWrapper::height)
        .def("how_many_bytes", &CimageWrapper::how_many_bytes)
        .staticmethod("how_many_bytes")
        .def("info", &CimageWrapper::info)
        ;

    class_<CprocWrapper, boost::noncopyable>(
            "Cproc", init<>())
        .def("run", &CprocWrapper::run)
        ;
}
