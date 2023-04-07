#include "main.h"

/**
 * print_binary - program prints the binary representation
 * of a number.
 * @n: unsigned long int.
 *
 * Return: no return.
 */

void print_binary(unsigned long int n)
{
	/*Binary Representation*/
	int b;

	if (n >> 1)
		print_binary(n >> 1);
	b = n & 1;
	putchar(b + '0');
}

