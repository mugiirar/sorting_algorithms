#include "sort.h"
/**
 * selection_sort - sorting an array
 * @array: the input array
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, min_index, j;
	int temp;
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
