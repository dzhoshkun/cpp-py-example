project(CppPythonWrapperExample)
cmake_minimum_required(VERSION 3.2)

# C++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
else()
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
    if(COMPILER_SUPPORTS_CXX0X)
        list(APPEND CMAKE_CXX_FLAGS "-std=c++0x")
    else()
        message(FATAL_ERROR
            "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
    endif()
endif()
list(REMOVE_DUPLICATES CMAKE_CXX_FLAGS)

set(CPP_LIB mycpp)
add_library(${CPP_LIB} SHARED cimage.h cimage.cpp
                              cproc.h cproc.cpp
                              file.h file.cpp
                              except.h except.cpp
                              gil.h)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

find_package(Boost COMPONENTS python REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(PY_LIB py${CPP_LIB})
add_library(${PY_LIB} SHARED python.cpp)
target_link_libraries(${PY_LIB} ${PYTHON_LIBRARIES} ${Boost_LIBRARIES} ${CPP_LIB})
# no lib prefix
set_target_properties(${PY_LIB} PROPERTIES PREFIX "")
