#include "hash_tables.h"

/**
 * hash_table_delete - delete table
 * @sb: pointer to struct of hash table
 *
 * Description: free and delete hash table
 * Return: na
 */
void hash_table_delete(hash_table_t *sb)
{
	unsigned int point = 0;
	hash_node_t *sbx = NULL, *ahd = NULL;

	while (point < sb->size)
	{
		sbx = sb->array[point];
		while (sbx)
		{
			ahd = sbx->next;
			free(sbx->value);
			free(sbx->key);
			free(sbx);
			sbx = ahd;
		}
		point++;
	}
	free(sb->array);
	free(sb);
}
