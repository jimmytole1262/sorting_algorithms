#include "sort.h"

/**
 * heapify - function that fix root of element
 * @array: array contain elements int
 * @size: size of array minus nth index
 * @origin_size: size of array
 * @index: index of root
*/

void heapify(int *array, size_t size, size_t index, size_t origin_size)
{
	size_t l = index * 2 + 1, max = index;
	size_t r = index * 2 + 2, tmp;

	if (l < size && array[l] > array[max])
		max = l;
	if (r < size && array[r] > array[max])
		max = r;
	if (max != index)
	{
		tmp = array[index];
		array[index] = array[max];
		array[max] = tmp;
		print_array(array, origin_size);
		heapify(array, size, max, origin_size);
	}
}

/**
 * heap_sort - function that sort array 'heap sort'
 * @array: array contain elements int
 * @size: size of array
*/

void heap_sort(int *array, size_t size)
{
	size_t i, j, tmp;

	if (!array || size < 2)
		return;
	for (i = size / 2 - 1; (int)i >= 0; i--)
		heapify(array, size, i, size);
	for (j = size - 1; (int)j >= 0; j--)
	{
		tmp = array[j];
		array[j] = array[0];
		array[0] = tmp;
		if (j != 0)
			print_array(array, size);
		heapify(array, j, 0, size);
	}
}
