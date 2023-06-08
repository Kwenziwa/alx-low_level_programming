#include "hash_tables.h"

/**
 * hash_table_get - get key/value
 * @vx: pointer to hash table structure
 * @ky: key to match
 *
 * Description: look for key in hash table
 * Return: value associated or NULL if no key
 */
char *hash_table_get(const hash_table_t *vx, const char *ky)
{
	hash_node_t *ptv = NULL;
	unsigned int point;

	if (vx && ky)
	{
		point = key_index((unsigned char *)ky, vx->size);
		ptv = vx->array[point];
		if (ptv == NULL)
			return (NULL);
		while (strcmp(ptv->key, ky) != 0)
			ptv = ptv->next;
		return (ptv->value);
	}
	return (NULL);
}
