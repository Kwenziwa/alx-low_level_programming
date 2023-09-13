#include "search_algos.h"

/**
 * interpolation_search - search algorithm
 * @array: input array
 * @size: size of the elements in the array
 * @value: value to search for
 * Return: index of the number in the array
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t posi, lit, hgh;
	double v;

	if (array == NULL)
		return (-1);

	lit = 0;
	hgh = size - 1;

	while (size)
	{
		v = (double)(hgh - lit) / (array[hgh] - array[lit]) * (value - array[lit]);
		posi = (size_t)(lit + v);
		printf("Value checked array[%d]", (int)posi);

		if (posi >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[posi]);
		}

		if (array[posi] == value)
			return ((int)posi);

		if (array[posi] < value)
			lit = posi + 1;
		else
			hgh = posi - 1;

		if (lit == hgh)
			break;
	}

	return (-1);
}
