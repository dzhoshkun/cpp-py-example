# Summary

Example project for hybrid programming using C++ and Python.

# Requirements

* Cmake
* C++11 compatible compiler
* Boost.Python version 1.63
* Python 3
* Tested on an Ubuntu 16.04 LTS.

# Usage

1. `git clone git@github.com:dzhoshkun/cpp-py-example.git`
1. `cd cpp-py-example/ex && export PYTHONPATH="$(pwd):$PYTHONPATH" && cd ../..`
1. `mkdir cpp-py-example-build && cd cpp-py-example-build`
1. `cmake ../cpp-py-example/src`
1. `make -j`
1. `export PYTHONPATH="$(pwd):$PYTHONPATH"`
1. `cd ../cpp-py-example/res`
1. Run one of the examples, e.g. `python3 ../ex/gil.py`
