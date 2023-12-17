#include "sort.h"

/**
 * selection_sort - function that sort array ascending selection method
 * @array: the array to be sorted
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t min_index, i, j, tmp;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
			if (array[min_index] > array[j])
				min_index = j;
		if (min_index != i)
		{
			tmp = array[min_index];
			array[min_index] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
