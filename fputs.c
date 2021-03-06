#include <Python.h>


static PyObject *method_puts(PyObject *self, PyObject *args) {
    char *str, *filename = NULL;
    int bytes_copied = -1;

    if (!PyArg_ParseTuple(args, "ss", &str, &filename)) {
        return NULL;
    }

    FILE *fp = fopen(filename, "w");
    bytes_copied = fputs(str, fp);
    fclose(fp);

    return PyLong_FromLong(bytes_copied);

}


static PyMethodDef FputsMethods[] = {
        {"fputs", method_puts, METH_VARARGS, "Python interface for fputs C library function"},
        {NULL, NULL, 0, NULL}
};


static struct PyModuleDef fputsmodule = {
        PyModuleDef_HEAD_INIT,
        "fputs",
        "Python interface for the fputs C library function",
        -1,
        FputsMethods
};


PyMODINIT_FUNC PyInit_fputs(void) {
    return PyModule_Create(&fputsmodule);
}