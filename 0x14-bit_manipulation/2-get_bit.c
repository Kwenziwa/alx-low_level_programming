#include "main.h"

/**
 *get_bit - Returns the value of a bit at a given index.
 *@n: number
 *@index: index
 *
 *Return: bit in index
 */

/**
 *Author - Kwenziwa Khanyile
 *Filename - 2-get_bit.c
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int binary, num;

	binary = (sizeof(n) * 8);
	num = -1;

	if (index < binary)
	{
		return (((1 << index) & n) >> index);
	}

	return (num);
}

