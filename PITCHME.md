# Hybrid Programming with C++ and Python

---

# Resources

* Boost.Python website: http://www.boost.org/libs/python/ (see esp. "Boost.Python NumPy Extension Documentation")
* StackOverflow
* Google
* Python website: https://www.python.org

**Always use up-to-date docs!**

---

# Exposing a class

1. [Bitmap class (C++)](https://github.com/dzhoshkun/cpp-py-example/blob/master/src/bitmap.h)
1. [Boost.Python module (C++ => Python)](https://github.com/dzhoshkun/cpp-py-example/blob/exposing-classes-directly/src/python.cpp)
1. [Using Bitmap class in Python](https://github.com/dzhoshkun/cpp-py-example/blob/master/ex/class.py)

---

# Mapping exceptions

1. [`FileError` (C++)](https://github.com/dzhoshkun/cpp-py-example/blob/master/src/except.h)
1. [`FileError` mapped to Python's `OSError`](https://github.com/dzhoshkun/cpp-py-example/blob/mapping-exceptions/src/python.cpp)

---

# Discussion

* A lot of duplicate code!
* Auto discovery?
* For NumPy arrays, compare ["old" code](http://stackoverflow.com/q/30388170)
