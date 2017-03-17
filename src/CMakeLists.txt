project(CppPythonWrapperExample)
cmake_minimum_required(VERSION 3.2)

set(CPP_LIB mycpp)
add_library(${CPP_LIB} SHARED cimage.h cimage.cpp)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

find_package(Boost COMPONENTS python REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(PY_LIB py${CPP_LIB})
add_library(${PY_LIB} SHARED python.cpp)
target_link_libraries(${PY_LIB} ${PYTHON_LIBRARIES} ${Boost_LIBRARIES} ${CPP_LIB})
# no lib prefix
set_target_properties(${PY_LIB} PROPERTIES PREFIX "")
