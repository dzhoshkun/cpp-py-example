#pragma once

#include <boost/python.hpp>

class ScopedPythonGILRelease
{
protected:
    PyThreadState * _thread_state;

public:
    inline ScopedPythonGILRelease()
        : _thread_state(nullptr)
    {
        if (PyEval_ThreadsInitialized() != 0)
            _thread_state = PyEval_SaveThread();
    }

    inline ~ScopedPythonGILRelease()
    {
        if (_thread_state != nullptr)
        {
            PyEval_RestoreThread(_thread_state);
            _thread_state = nullptr;
        }
    }
};

class ScopedPythonGILLock
{
protected:
    PyGILState_STATE _gil_state;
public:
    inline ScopedPythonGILLock()
    {
        _gil_state = PyGILState_Ensure();
    }

    inline ~ScopedPythonGILLock()
    {
        PyGILState_Release(_gil_state);
    }
};
