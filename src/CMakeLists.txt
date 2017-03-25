project(CppPythonWrapperExample)
cmake_minimum_required(VERSION 3.2)


# Check compiler C++11 support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
else(COMPILER_SUPPORTS_CXX11)
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
    if(COMPILER_SUPPORTS_CXX0X)
        list(APPEND CMAKE_CXX_FLAGS "-std=c++0x")
    else(COMPILER_SUPPORTS_CXX0X)
        message(FATAL_ERROR
            "Compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
    endif(COMPILER_SUPPORTS_CXX0X)
endif(COMPILER_SUPPORTS_CXX11)
list(REMOVE_DUPLICATES CMAKE_CXX_FLAGS)


# Build our C++ library
set(CPP_LIB mycpp)
add_library(${CPP_LIB} SHARED bitmap.h bitmap.cpp
                              proc.h proc.cpp
                              except.h except.cpp
                              gil.h)


# Discover Python development libs
find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})


# Discover Boost.Python (incl. NumPy) libs
find_package(Boost COMPONENTS python numpy REQUIRED)
include_directories(${Boost_INCLUDE_DIR})


# Build Python module of our C++ library
set(PY_LIB py${CPP_LIB})
add_library(${PY_LIB} SHARED python.cpp)
target_link_libraries(${PY_LIB} ${PYTHON_LIBRARIES}
                                ${Boost_LIBRARIES}
                                ${CPP_LIB})
# no lib prefix
set_target_properties(${PY_LIB} PROPERTIES PREFIX "")
