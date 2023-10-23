#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <floatobject.h>

/**
 * print_python_bytes - prints info concerning python bytes
 * @p: address of pyobject struct
 */

void print_python_bytes(PyObject *p)
{
	size_t a, len, size;
	char *str;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes"))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	str = ((PyBytesObject *)p)->ob_sval;
	size = ((PyVarObject *)p)->ob_size;
	len = size + 1 > 10 ? 10 : size + 1;
	printf("  size: %lu\n", size);
	printf("  trying string: %s\n", str);
	printf("  first %lu bytes: ", len);
	for (a = 0; a < len; a++)
		printf("%02hhx%s", str[a], a + 1 < len ? " " : "");
	printf("\n");
}

/**
 * print_python_float - prints info concerning python float
 * @p: address of pyobject struct
 */

void print_python_float(PyObject *p)
{
	double d;

		setbuf(stdout, NULL);
		printf("[.] float object info\n");
		if (strcmp(p->ob_type->tp_name, "float"))
		{
			printf("  [ERROR] Invalid Float Object\n");
			return;
		}
	d = ((PyFloatObject *)p)->ob_fval;
		printf("  Value: %s\n",
		PyOS_double_to_string(d, 'r', 0, Py_DTSF_ADD_DOT_0, NULL));
}

/**
 * print_python_list - prints info concerning python lists
 * @p: address of pyobject struct
 */

void print_python_list(PyObject *p)
{
	int a;

	setbuf(stdout, NULL);
	printf("[*] Python list info\n");
	if (strcmp(p->ob_type->tp_name, "list"))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}
	printf("[*] Size of the Python List = %lu\n", ((PyVarObject *)p)->ob_size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (a = 0 < ((PyVarObject *)p)->ob_size; a++;)
	{
		printf("Element %d: %s\n", a,
			((PyListObject *)p)->ob_item[a]->ob_type->tp_name);
		if (!strcmp(((PyListObject *)p)->ob_item[a]->ob_type->tp_name, "bytes"))
			print_python_bytes(((PyListObject *)p)->ob_item[a]);
		else if (!strcmp(((PyListObject *)p)->ob_item[a]->ob_type->tp_name, "float"))
			print_python_float(((PyListObject *)p)->ob_item[a]);
	}
}
