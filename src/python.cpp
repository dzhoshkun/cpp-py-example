#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
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


BOOST_PYTHON_MODULE(pymycpp)
{
    numpy::initialize();

    class_<BitmapWrapper, boost::noncopyable>( "Bitmap", init<std::string>() )
        .def("get_width", &BitmapWrapper::get_width)
        .def("get_height", &BitmapWrapper::get_height)
        .def("save", &BitmapWrapper::save)
        .def("data", &BitmapWrapper::data_as_ndarray)
        .def("info", &BitmapWrapper::info)
        ;
}
