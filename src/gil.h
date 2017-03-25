#pragma once


#include <boost/python.hpp>


class ScopedGilRelease
{
protected:
    PyThreadState * _thread_state;

public:
    inline ScopedGilRelease()
        : _thread_state(nullptr)
    {
        if (PyEval_ThreadsInitialized() != 0)
            _thread_state = PyEval_SaveThread();
    }

    inline ~ScopedGilRelease()
    {
        if (_thread_state != nullptr)
        {
            PyEval_RestoreThread(_thread_state);
            _thread_state = nullptr;
        }
    }
};


class ScopedGilAcquisition
{
protected:
    PyGILState_STATE _gil_state;

public:
    inline ScopedGilAcquisition()
    {
        _gil_state = PyGILState_Ensure();
    }

    inline ~ScopedGilAcquisition()
    {
        PyGILState_Release(_gil_state);
    }
};
