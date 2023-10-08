#include <stdlib.h>
#include <stdio.h>
#include <Python.h>
/**
 * print_python_list_info -  function that prints info about Python lists
 *
 * @p: python list
 */
void print_python_list_info(PyObject *p)
{
	int dat_a;

	printf("[*] Size of the Python List = %lu\n", Py_SIZE(p));
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (dat_a = 0; dat_a < Py_SIZE(p); dat_a++)
		printf("Element %d: %s\n", dat_a, Py_TYPE(PyList_GetItem(p, dat_a))->tp_name);
}
