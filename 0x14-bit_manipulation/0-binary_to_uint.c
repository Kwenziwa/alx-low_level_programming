/*
 * File Name: 0-binary_to_uint.c
 * Author: Kwenziwa Khanyile
 * Date: 06 April 2023
 */

#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 * Return: If b is NULL or contains chars not 0 or 1 - 0.
 * Otherwise - the converted number.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int converted_num = 0, mult_num = 1;
	int len;

	if (!b)
		return (0);

	for (len = 0; b[len];){
		len++;
	}

	for (len -= 1; len >= 0; len--)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		converted_num += (b[len] - '0') * mult_num;
		mult_num *= 2;
	}

	return (converted_num);
}
