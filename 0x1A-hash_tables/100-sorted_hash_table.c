#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int asz);
int shash_table_set(shash_table_t *tsz, const char *key, const char *value);
char *shash_table_get(const shash_table_t *tsz, const char *key);
void shash_table_print(const shash_table_t *tsz);
void shash_table_print_rev(const shash_table_t *tsz);
void shash_table_delete(shash_table_t *tsz);

/**
 * shash_table_create - Creates a sorted hash table.
 * @asz: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int asz)
{
	shash_table_t *tsz;
	unsigned long int x;

	tsz = malloc(sizeof(shash_table_t));
	if (tsz == NULL)
		return (NULL);

	tsz->size = asz;
	tsz->array = malloc(sizeof(shash_node_t *) * asz);
	if (tsz->array == NULL)
		return (NULL);
	for (x = 0; x < asz; x++)
		tsz->array[x] = NULL;
	tsz->shead = NULL;
	tsz->stail = NULL;

	return (tsz);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @tsz: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *tsz, const char *key, const char *value)
{
	shash_node_t *nw, *holder;
	char *value_copy;
	unsigned long int index;

	if (tsz == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, tsz->size);
	holder = tsz->shead;
	while (holder)
	{
		if (strcmp(holder->key, key) == 0)
		{
			free(holder->value);
			holder->value = value_copy;
			return (1);
		}
		holder = holder->snext;
	}

	nw = malloc(sizeof(shash_node_t));
	if (nw == NULL)
	{
		free(value_copy);
		return (0);
	}
	nw->key = strdup(key);
	if (nw->key == NULL)
	{
		free(value_copy);
		free(nw);
		return (0);
	}
	nw->value = value_copy;
	nw->next = tsz->array[index];
	tsz->array[index] = nw;

	if (tsz->shead == NULL)
	{
		nw->sprev = NULL;
		nw->snext = NULL;
		tsz->shead = nw;
		tsz->stail = nw;
	}
	else if (strcmp(tsz->shead->key, key) > 0)
	{
		nw->sprev = NULL;
		nw->snext = tsz->shead;
		tsz->shead->sprev = nw;
		tsz->shead = nw;
	}
	else
	{
		holder = tsz->shead;
		while (holder->snext != NULL && strcmp(holder->snext->key, key) < 0)
			holder = holder->snext;
		nw->sprev = holder;
		nw->snext = holder->snext;
		if (holder->snext == NULL)
			tsz->stail = nw;
		else
			holder->snext->sprev = nw;
		holder->snext = nw;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @tsz: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in tsz.
 */
char *shash_table_get(const shash_table_t *tsz, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (tsz == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, tsz->size);
	if (index >= tsz->size)
		return (NULL);

	node = tsz->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @tsz: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *tsz)
{
	shash_node_t *node;

	if (tsz == NULL)
		return;

	node = tsz->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @tsz: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *tsz)
{
	shash_node_t *node;

	if (tsz == NULL)
		return;

	node = tsz->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @tsz: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *tsz)
{
	shash_table_t *head = tsz;
	shash_node_t *node, *holder;

	if (tsz == NULL)
		return;

	node = tsz->shead;
	while (node)
	{
		holder = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = holder;
	}

	free(head->array);
	free(head);
}
