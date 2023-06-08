#include "hash_tables.h"

/**
 * key_index - give the index of a key
 * @ky: key value to check for index
 * @sz: size of array of the hash table
 *
 * Description: find the index with key arg within size for array
 * Return: index
 */
unsigned long int key_index(const unsigned char *ky, unsigned long int sz)
{
	return (hash_djb2(ky) % sz);
}
