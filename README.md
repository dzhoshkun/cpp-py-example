# Summary

Example project for hybrid programming using C++ and Python.

# Requirements

* Cmake version 3.2 or newer
* C++11 compatible compiler
* Boost.Python version 1.63
* Python 3
* Tested on an Ubuntu 16.04 LTS.

See towards the end of this file for instructions how to install these.

# Usage

1. `git clone git@github.com:dzhoshkun/cpp-py-example.git`
1. `cd cpp-py-example/ex && export PYTHONPATH="$(pwd):$PYTHONPATH" && cd ../..`
1. `mkdir cpp-py-example-build && cd cpp-py-example-build`
1. `cmake ../cpp-py-example/src`
1. `make -j`
1. `export PYTHONPATH="$(pwd):$PYTHONPATH"`
1. `cd ../cpp-py-example/res`
1. Run one of the examples, e.g. `python3 ../ex/gil.py`

# Installing requirements

## Cmake

`apt install cmake`

## Boost.Python 1.63

1. `wget https://sourceforge.net/projects/boost/files/boost/1.63.0/boost_1_63_0.tar.bz2`
1. `tar xvfj boost_1_63_0.tar.bz2`
1. `./bootstrap.sh --with-python=$(which python3)`
1. `./b2 -j 7`
1. `./b2 -j 7 install`

## Python 3

`apt install python3-dev`
