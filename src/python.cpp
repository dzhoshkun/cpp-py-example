#include <boost/python.hpp>
#include "bitmap.h"


using namespace boost::python;


BOOST_PYTHON_MODULE(pymycpp)
{
    class_<Bitmap, boost::noncopyable>(
            "Bitmap", init<std::string>())
        .def("get_width", &Bitmap::get_width)
        .def("get_height", &Bitmap::get_height)
        .def("save", &Bitmap::save)
        ;
}
