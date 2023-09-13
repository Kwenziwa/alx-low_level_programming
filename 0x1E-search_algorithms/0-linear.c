#include <stdlib.h>
#include <stdio.h>

#include "search_algos.h"

/**
 * linear_search - searches for a n_v in an v_arr of
 * integers using the Linear search algorithm
 * @v_arr: input array
 * @v_sz: size of the array
 * @n_v: value to search in
 * Return: Always EXIT_SUCCESS
 */
int linear_search(int *v_arr, size_t v_sz, int n_v)
{
	int v;

	if (v_arr == NULL)
		return (-1);

	for (v = 0; v < (int)v_sz; v++)
	{
		printf("n_v checked v_arr[%u] = [%d]\n", v, v_arr[v]);
		if (n_v == v_arr[v])
			return (v);
	}
	return (-1);
}
