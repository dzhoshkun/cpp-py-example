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

## Running the examples

Some `*.py` files in the `ex` folder contain main functions.
These can be run using e.g. `python3 ../ex/gil.py`

## Running the benchmarks

The `mgrad.py` file in the `ex` folder is intended for benchmarking.
You can benchmark the pure Python function in this file using e.g.:
```
python3 -m timeit "from mgrad import grad; import numpy as np; arr = np.zeros((128, 128, 3), dtype='uint8'); grad(arr)"
```
To benchmark its C++ implementation, replace `mgrad` with `pymycpp`, i.e:
```
python3 -m timeit "from pymycpp import grad; import numpy as np; arr = np.zeros((128, 128, 3), dtype='uint8'); grad(arr)"
```

# Installing requirements

## Cmake

`apt install cmake`

## Boost.Python 1.63

1. Install Python 3 development libs (see below).
1. `wget https://sourceforge.net/projects/boost/files/boost/1.63.0/boost_1_63_0.tar.bz2`
1. `tar xvfj boost_1_63_0.tar.bz2`
1. `./bootstrap.sh --with-python=$(which python3)`
1. `./b2 -j 7`
1. `./b2 -j 7 install`

## Python 3

`apt install python3-dev`
