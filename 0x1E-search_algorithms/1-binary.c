#include "search_algos.h"

/**
 * r_search - searches for a n_v in an v_arr of
 * integers using the Binary search algorithm
 *
 *
 * @v_arr: input v_arr
 * @vsize: vsize of the v_arr
 * @n_v: value tosearch in
 * Return: index of the number
 */
int r_search(int *v_arr, size_t vsize, int n_v)
{
	size_t myhl = vsize / 2;
	size_t i;

	if (v_arr == NULL || vsize == 0)
		return (-1);

	printf("Searching in v_arr");

	for (i = 0; i < vsize; i++)
		printf("%s %d", (i == 0) ? ":" : ",", v_arr[i]);

	printf("\n");

	if (myhl && vsize % 2 == 0)
		myhl--;

	if (n_v == v_arr[myhl])
		return ((int)myhl);

	if (n_v < v_arr[myhl])
		return (r_search(v_arr, myhl, n_v));

	myhl++;

	return (r_search(v_arr + myhl, vsize - myhl, n_v) + myhl);
}

/**
 * binary_search - calls to binary_search to return
 * the index of the number
 *
 * @v_arr: input v_arr
 * @vsize: vsize of the v_arr
 * @n_v: value tosearch in
 * Return: index of the number
 */
int binary_search(int *v_arr, size_t vsize, int n_v)
{
	int v;

	v = r_search(v_arr, vsize, n_v);

	if (v >= 0 && v_arr[v] != n_v)
		return (-1);

	return (v);
}
