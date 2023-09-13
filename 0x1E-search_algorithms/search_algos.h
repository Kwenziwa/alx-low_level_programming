#ifndef _SORTING_ALGOS_H_
#define _SORTING_ALGOS_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - singly linked list
 *
 * @n_v: Integer
 * @indx: index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n_v;
	size_t indx;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n_v: Integer
 * @indx: index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
	int n_v;
	size_t indx;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

int interpolation_search(int *arr, size_t mysize, int num_v);
int linear_search(int *arr, size_t mysize, int num_v);
int binary_search(int *arr, size_t mysize, int num_v);
int jump_search(int *arr, size_t mysize, int num_v);
int advanced_binary(int *arr, size_t mysize, int num_v);
int exponential_search(int *arr, size_t mysize, int num_v);
skiplist_t *linear_skip(skiplist_t *list, int num_v);
listint_t *jump_list(listint_t *list, size_t mysize, int num_v);

#endif
