#include "hash_tables.h"

/**
 * hash_djb2 - hash function djb2 style
 * @a_srng: key value
 *
 * Description: compute index with djb2 algorithm
 * Return: hash code
 */
unsigned long int hash_djb2(const unsigned char *a_srng)
{
	unsigned long int h_sh;
	int c;

	h_sh = 5381;
	while ((c = *a_srng++))
	{
		h_sh = ((h_sh << 5) + h_sh) + c; /* h_sh * 33 + c */
	}
	return (h_sh);
}
