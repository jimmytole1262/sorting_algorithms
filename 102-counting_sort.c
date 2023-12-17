#include "sort.h"

/**
 * counting_sort - function that sort an array
 * @array: array of element
 * @size: size of array
*/

void counting_sort(int *array, size_t size)
{
	size_t largest, i = 0;
	int *array_index, *new_array;

	if (!array || size < 2)
		return;
	largest = array[i];
	/*find largest number in the array*/
	for (; i < size; i++)
		if ((size_t)array[i] >= largest)
			largest = array[i];
	largest += 1;

	/*Reserve memory*/
	array_index = calloc(largest, sizeof(int));
	new_array = calloc(size, sizeof(int));
	if (!array_index || !new_array)
		return;
	/*iterate from array value and add 1 for each index*/
	for (i = 0; i < size; i++)
		array_index[array[i]] += 1;
	/*sum two first index and so on*/
	for (i = 1; i < largest; i++)
		array_index[i] += array_index[i - 1];

	/*assign the sorted array to new_array*/
	for (i = 0; i < size; i++)
	{
		new_array[(array_index[array[i]]) - 1] = array[i];
		/*array_index[array[i]] -= 1;*/
	}

	/*assign the value of array to new_array*/
	for (i = 0; i < size; i++)
		array[i] = new_array[i];

	print_array((const int *)array_index, largest);
	free(array_index);
	free(new_array);
}
