#include "main.h"

/**
 * get_endianness - function that checks the endianness
 *
 * Return: 0 if it a big endian, 1 if it a little endian
 */
int get_endianness(void)
{	
	int x = 1;
	char *c = (char *) &x;

	return ((int)*c);
}
