#include <boost/python.hpp>
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

        std::string info() const
        {
            if (override f = this->get_override("info"))
                return f();
            else
                return Bitmap::info();
        }
};


BOOST_PYTHON_MODULE(pymycpp)
{
    class_<BitmapWrapper, boost::noncopyable>( "Bitmap", init<std::string>() )
        .def("get_width", &BitmapWrapper::get_width)
        .def("get_height", &BitmapWrapper::get_height)
        .def("save", &BitmapWrapper::save)
        .def("info", &BitmapWrapper::info)
        ;
}
