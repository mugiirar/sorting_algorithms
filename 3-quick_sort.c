#include "sort.h"

/**
 * swap_ints - swap two integers
 * @a: int
 * @b: int
 * Return: nothing
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partitioning of an array and using pivot
 * @array: the array input
 * @low: integer
 * @high: integer
 * @size: size of array
 * Return: index of pivote
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap_ints(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap_ints(&array[i], &array[high]);
	if (i != high)
		print_array(array, size);
	return (i);
}

/**
 * quick_sort_helper - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Quick Sort Algorithm using lomuto partition scheme
 * @array: Array to be sorted
 * @size: Size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quick_sort_helper(array, 0, size - 1, size);
}
