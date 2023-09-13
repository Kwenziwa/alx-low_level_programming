#include "search_algos.h"
#include <math.h>

/**
 * jump_search - search algorithm
 * @array: input array
 * @size: size of the elements in the array
 * @value: value to search for
 * Return: ix of the number in the array
 */
int jump_search(int *array, size_t size, int value)
{
	int ix, i, j, prv;

	if (array == NULL || size == 0)
		return (-1);

	i = (int)sqrt((double)size);
	j = 0;
	prv = ix = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", ix, array[ix]);

		if (array[ix] == value)
			return (ix);
		j++;
		prv = ix;
		ix = j * i;
	} while (ix < (int)size && array[ix] < value);

	printf("Value found between indexes [%d] and [%d]\n", prv, ix);

	for (; prv <= ix && prv < (int)size; prv++)
	{
		printf("Value checked array[%d] = [%d]\n", prv, array[prv]);
		if (array[prv] == value)
			return (prv);
	}

	return (-1);
}
