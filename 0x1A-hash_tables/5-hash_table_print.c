#include "hash_tables.h"

/**
 * hash_table_print - function
 * @tsz: pointer to hash table structure
 *
 * Description: print all element of hash table
 * Return: na
 */
void hash_table_print(const hash_table_t *tsz)
{
	hash_node_t *sbx = NULL;
	unsigned int point = 0, hold = 0;

	if (tsz == NULL)
		return;

	printf("{");
	while (point < tsz->size)
	{
		if (tsz->array[point] == NULL)
		{
			point++;
			continue;
		}
		if (hold == 1)
			printf(", ");
		hold = 1;
		sbx = tsz->array[point];
		while (sbx)
		{
			printf("'%s': '%s'", sbx->key, sbx->value);
			if (sbx->next != NULL)
				printf(", ");
			sbx = sbx->next;
		}
		point++;
	}
	printf("}\n");
}
