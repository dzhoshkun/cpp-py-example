project(CppPythonWrapperExample)
cmake_minimum_required(VERSION 3.2)

set(CPP_LIB mycpp)
add_library(${CPP_LIB} SHARED cimage.h cimage.cpp)
