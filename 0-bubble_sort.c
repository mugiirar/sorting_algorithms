#include "sort.h"

/**
 * bubble_sort - arrange numbers in ascending order
 * @array: the array of numbers
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t p, k;
	int number;

	if (array == NULL || size < 2)
		return;
	p = 0;
	while (p < size - 1)
	{
		k = 0;
		while (k < size - p - 1)
		{
			if (array[k] > array[k + 1])
			{
				number = array[k];
				array[k] = array[k + 1];
				array[k + 1] = number;
				print_array(array, size);
			}
			k++;
		}
		p++;
	}
}
