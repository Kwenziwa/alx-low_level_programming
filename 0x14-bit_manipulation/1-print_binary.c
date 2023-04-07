/**
 * Filename: 1-print_binary.c
 * Auth: Kwenziwa Khanyile
 */

#include "main.h"
/**
 * print_binary - function that prints the binary representation of a number
 * The number to be printed in binary.
 * @num: unsigned long int.
 * Return: no return.
 */
void print_binary(unsigned long int num)
{
	/*Binary Representation*/
	int b;

	if (num >> 1)
		print_binary(num >> 1);
	b = num & 1;
	putchar(b + '0');
}
