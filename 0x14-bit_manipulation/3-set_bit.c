#include "main.h"

/**
 * set_bit - program sets the value of a bit to 1.
 * at a given index.
 * @n: unsigned long int.
 * @index: the bit.
 *
 * Return: 1 on success, -1 on failed.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int num;

	if (index > 63)
		return (-1);

	num = 1 << index;
	*n = (*n | num);

	return (1);
}
