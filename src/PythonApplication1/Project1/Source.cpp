#include <Python.h>  //always put Python header first, if not found this header, check c++ Additional library include setting
#include <Windows.h>
#include "math.h"

PyObject* test_mul(PyObject *self, PyObject* args) {
	int a, b;
	PyArg_ParseTuple(args, "ii", &a, &b);  //format string ref: https://docs.python.org/3.7/c-api/arg.html
	//return PyLong_FromLong(a*b);
	int result = mul(a, b);
	return PyLong_FromLong(result);
}

PyObject* test_sub(PyObject* self, PyObject* args) {
	int a, b;
	PyArg_ParseTuple(args, "ii", &a, &b);
	int result = sub(a, b);
	return PyLong_FromLong(result);
}


static PyMethodDef superfastcode_methods[] = {
	// The first property is the name exposed to Python, fast_tanh, the second is the C++
	// function name that contains the implementation.
	//{ "fast_tanh", (PyCFunction)tanh_impl, METH_O, nullptr },  //METH_O means only passing one argument
	{"test_mul", (PyCFunction)test_mul, METH_VARARGS, nullptr},  //METH_VARARGS ref: https://docs.python.org/3/c-api/structures.html
	{"test_sub", (PyCFunction)test_sub, METH_VARARGS, nullptr},
	// Terminate the array with an object containing nulls.
	{ nullptr, nullptr, 0, nullptr }
};

static PyModuleDef superfastcode_module = {
	PyModuleDef_HEAD_INIT,
	"superfastcode",                        // Module name to use with Python import statements
	"Provides some functions, but faster",  // Module description
	0,
	superfastcode_methods                   // Structure that defines the methods of the module
};

PyMODINIT_FUNC PyInit_superfastcode() {  //PyInit_<module_name>  module_name must be your module name
	return PyModule_Create(&superfastcode_module);
}