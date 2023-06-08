#ifndef HASH_TABLES_H_
#define HASH_TABLES_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>



unsigned long int hash_djb2(const unsigned char *str);
hash_table_t *hash_table_create(unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);
char *hash_table_get(const hash_table_t *ht, const char *key);



/**
 * struct hash_node_s - The node of hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - The hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * One and all cell of this array is a pointing to the 1st node of a  list that is linked
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;
#endif
