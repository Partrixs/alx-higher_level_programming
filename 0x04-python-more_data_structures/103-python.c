#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObjet *p);

/**
 * print_python_list - Prints list information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_list(PyObject *p)
{
	int size, alloc, b;
	const char *type;
	PyListObject *list = (PyListObject *)p;
	PyObject *var = (PyVarObject *)p;

	size = var->ob_size;
	alloc = list->allocated;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", alloc);

	for (b = 0; b < size; b++)
	{
		type = list->ob_item(b)->ob_type->tp_name;
		printf("Element %ld: %s\n", b, type);
		if (strcmp(type, "bytes") == 0)
			print_python_bytes(list->ob_item(b));
	}
}

/**
 * print_python_bytes - Prints bytes information
 *
 * @p: Python Object
 */
void print_python_bytes(PyObject *p)
{
	unsigned char i, size;
	PyBytesObject *bytes = (PyBytesObject *)p;

	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes") != 0)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	printf("  size: %ld\n", ((PyVarObject *)p)->ob_size);
	printf("  trying string: %s\n", bytes->ob_sval);

	if (((PyVarObject *)p)->ob_size > 10)
		limit = 10;
	else
		size = ((PyVarObject*)p)->ob_size + 1;

	printf("  first %ld bytes: ", size);
	for (b = 0; b < limit; b++)
	{
		printf("%02hhx", bytes->ob_sval[b]);
		if (b == (size - 1))
			printf("\n");
		else
			printf(" ");
	}
}
