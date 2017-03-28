#include <boost/python.hpp>
#include <boost/python/numpy.hpp>


using namespace boost::python;


void grad_ndarray(numpy::ndarray arr)
{
    uint8_t * data = reinterpret_cast<uint8_t *>(arr.get_data());
    size_t width = arr.shape(1);
    size_t height = arr.shape(0);
    grad(data, width, height);
}


BOOST_PYTHON_MODULE(pymycpp)
{
    numpy::initialize();
    
    def("grad", &grad_ndarray);
}
