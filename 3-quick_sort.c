#include "sort.h"
/**
 * copy_array - func that copy array
 * @source: original array
 * @destination: copy array
 * @size: size of array
*/
void copy_array(int source[], int destination[], size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		destination[i] = source[i];
}

/**
 * is_array_equal - func that cchek if arrays are equals
 * @arr1: first array
 * @arr2: second array
 * @size: size of array
 * Return: true if equal otherwise false
*/
bool is_array_equal(int arr1[], int arr2[], size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		if (arr1[i] != arr2[i])
			return (false);
	return (true);
}

/**
 * lomuto_partition - Lomuto partition for Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;
	int array_copy[sizeof(array)];
	bool is_sorted;

	is_sorted = false;
	(void)is_sorted;
	(void)size;
	i = low - 1;
	pivot = array[high];
	copy_array(array, array_copy, size);
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			is_sorted = true;
			i++;
			if (i != j)
			{
				/* Swap array[i] and array[j] */
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	/* Print the array after each swap*/
	if (!is_array_equal(array, array_copy, size))
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort - Quick Sort using Lomuto partition
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - Helper function for Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the array/subarray
 * @high: Ending index of the array/subarray
 * @size: Size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{

	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_helper(array, low, pivot_index - 1, size);
		quick_sort_helper(array, pivot_index + 1, high, size);
	}
}
