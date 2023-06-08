#include "hash_tables.h"

/**
 * hash_table_create - function with one argument
 * @dimension: size of array
 *
 * Description: creates a hash table
 * Return: pointer to new hash table
 */
hash_table_t *hash_table_create(unsigned long int dimension)
{
	hash_table_t *first_t = NULL;
	hash_node_t **sec_t = NULL;

	sec_t = calloc(dimension, sizeof(char *));
	if (sec_t == NULL)
	{
		free(sec_t);
		return (NULL);
	}

	first_t = calloc(1, sizeof(hash_table_t));
	if (first_t == NULL)
		return (NULL);

	first_t->size = dimension;
	first_t->array = sec_t;
	return (first_t);
}
