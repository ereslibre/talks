#include <Python.h>

static PyObject *matematicas_suma(PyObject *self, PyObject *args)
{
    double a;
    double b;
    if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return 0;
    }
    return Py_BuildValue("d", a + b);
}

static PyMethodDef matematicas_methods[] = {
    { "suma", (PyCFunction) matematicas_suma, METH_VARARGS, 0  },
    { 0, 0, 0, 0 }
};

PyMODINIT_FUNC initmatematicas()
{
    Py_InitModule3("matematicas", matematicas_methods, "Extension module");
}
