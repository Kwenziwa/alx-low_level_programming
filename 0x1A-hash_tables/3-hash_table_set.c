#include "hash_tables.h"

/**
 * hash_table_set - Hash table function
 * @ct: pointer to start of table
 * @ky: key value of element
 * @vlu: value of key element
 *
 * Description: add an element to the hash table
 * Return: 1 for success or 0 otherwise
 */
int hash_table_set(hash_table_t *ct, const char *ky, const char *vlu)
{
	hash_node_t *vtr = NULL, *node = NULL;
	unsigned long int inx;

	if (!ct || !ky || !*ky || !vlu)
		return (0);

	inx = key_index((const unsigned char *)ky, ct->size);
	vtr = ct->array[inx];

	while (vtr)
	{
		if (strcmp(vtr->key, ky) == 0)
		{
			free(vtr->value);
			vtr->value = strdup(vlu);
			return (1);
		}
		vtr = vtr->next;
	}


	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		free(node);
		return (0);
	}

	node->key = strdup(ky);
	node->value = strdup(vlu);
	node->next = ct->array[inx];
	ct->array[inx] = node;
	return (1);
}
