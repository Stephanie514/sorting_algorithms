#include "sort.h"

/**
* swap - Swaps two array entries
* @one: int one
* @two: int two
*
* Return: Swapped int
*/

void swap(int *one, int *two)
{
	int tmp = *one;
	*one = *two;
	*two = tmp;
}

/**
* hoare_partition - Partitions an array with Hoare partition
* @array: array to partition
* @low: lowest partition index
* @high: highest partition index
* @size: Array size
* Return: Pivot index element
*/
int hoare_partition(int *array, int low, int high, size_t size)
{

	int pvt = array[high];

	int s = low - 1, f = high + 1;


	while (1)
	{
		do {
			s++;
		} while (array[s] < pvt);


		do {
			f--;
		} while (array[f] > pvt);

		if (s >= f)
			return (f);

		swap(&array[s], &array[f]);
		print_array(array, size);
	}
}

/**
* quick_sorts_hoare - Quicksorts array of ints recursively
* @array: Array to sort
* @low: Lowest array value
* @high: Highest array value
* @size: Array size
*/
void quick_sorts_hoare(int *array, int low, int high, size_t size)
{
	int s;

	if (low < high)
	{
		s = hoare_partition(array, low, high, size);

		quick_sorts_hoare(array, low, s, size);
		quick_sorts_hoare(array, s + 1, high, size);
	}
}

/**
* quick_sort_hoare - Quick Sort Algorithms
* @array: Array of ints to sort
* @size: Size of array
* Return: Sorted Array
*/
void quick_sort_hoare(int *array, size_t size)
{
	quick_sorts_hoare(array, 0, size - 1, size);
}
