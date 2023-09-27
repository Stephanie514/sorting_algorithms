#include "sort.h"

/**
 * swap - swap two int
 * @one: int one
 * @two: int two
 * Return: Swapped int
 */
void swap(int *one, int *two)
{
	int tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}
/**
 * partition - Parts an array using a pivot
 * @array: Array to sort
 * @low: lowest value
 * @high: highest value
 * @size: size of array (size_t)
 * Return: index of pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pvt = array[high];
	int s = low - 1, f;

	for (f = low; f <= high; f++)
	{
		if (array[f] <= pvt)
		{
			s++;
			if (s != f)
			{
				swap(&array[s], &array[f]);
				print_array(array, size);
			}
		}
	}
	return (s);
}
/**
 * lomuto_quicksort - Quicksorts Recursively
 * @array: Array to sort
 * @low: lowest value of the array
 * @high: highest value of the array
 * @size: array size
 * Return: void
 */
void lomuto_quicksort(int *array, int low, int high, size_t size)
{
	int f;

	if (low < high)
	{
		f = partition(array, low, high, size);
		lomuto_quicksort(array, low, f - 1, size);
		lomuto_quicksort(array, f + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithms
 * @array: array to sort
 * @size: array size
 * Return: sorted array
 */
void quick_sort(int *array, size_t size)
{
	lomuto_quicksort(array, 0, size - 1, size);
}
