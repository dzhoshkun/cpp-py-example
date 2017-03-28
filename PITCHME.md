# Hybrid Programming with C++ and Python

---

# Resources

* Boost.Python website: http://www.boost.org/libs/python/ (see esp. "Boost.Python NumPy Extension Documentation")
* StackOverflow
* Google
* Python website: https://www.python.org

**Always use up-to-date docs!**

---

# Exposing classes

1. [Bitmap class (C++)](https://github.com/dzhoshkun/cpp-py-example/blob/master/src/bitmap.h)
1. [Boost.Python module (C++ => Python)](https://github.com/dzhoshkun/cpp-py-example/blob/exposing-classes-directly/src/python.cpp)
1. [Using Bitmap class in Python](https://github.com/dzhoshkun/cpp-py-example/blob/master/ex/class.py)

---

# Exposing extensible classes

1. [`info` method added to Bitmap class (C++)](https://github.com/dzhoshkun/cpp-py-example/blob/master/src/bitmap.h#L25)
1. [Use `boost::python::wrapper`](https://github.com/dzhoshkun/cpp-py-example/blob/exposing-extensible-classes/src/python.cpp#L9)
1. [Query for function overrides](https://github.com/dzhoshkun/cpp-py-example/blob/exposing-extensible-classes/src/python.cpp#L20)
1. [Extending Bitmap class in Python](https://github.com/dzhoshkun/cpp-py-example/blob/master/ex/over.py#L11)

---

# Mapping exceptions

1. [`FileError` (C++)](https://github.com/dzhoshkun/cpp-py-example/blob/master/src/except.h)
1. [`FileError` mapped to Python's `OSError`](https://github.com/dzhoshkun/cpp-py-example/blob/mapping-exceptions/src/python.cpp)

---

# NumPy datatypes + SciPy routines

* C++ array => NumPy array:
   1. [`numpy::initialize()` your module](https://github.com/dzhoshkun/cpp-py-example/blob/numpy-data-scipy-routines/src/python.cpp#L41)
   1. [Choose "corresponding" NumPy data type](https://github.com/dzhoshkun/cpp-py-example/blob/numpy-data-scipy-routines/src/python.cpp#L23)
   1. [Choose NumPy array shape](https://github.com/dzhoshkun/cpp-py-example/blob/numpy-data-scipy-routines/src/python.cpp#L24)
   1. [Describe strides to be used by NumPy array](https://github.com/dzhoshkun/cpp-py-example/blob/numpy-data-scipy-routines/src/python.cpp#L27)
* [Owner??](https://github.com/dzhoshkun/cpp-py-example/blob/numpy-data-scipy-routines/src/python.cpp#L34)

---

#### You want to use multi-threading? <!-- .element: class="fragment" -->
## Then lo! and behold the GIL!! <!-- .element: class="fragment" -->

---

# Discussion

* A lot of duplicate code!
* Auto discovery?
* For NumPy arrays, compare ["old" code](http://stackoverflow.com/q/30388170)

---

# Do it yourself

All source code incl. examples available online: https://github.com/dzhoshkun/cpp-py-example

**Warning:** Some links in this presentation point to isolated source code for conciseness, so please always use the `master` branch when building the whole project
