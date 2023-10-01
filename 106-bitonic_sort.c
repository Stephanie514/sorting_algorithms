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
* bitonic_merge - merges two subarrays
* @array: subarrays
* @size: subarrays sizes
* @up: 1 for ascending order merging, 0 for descending order
*/
void bitonic_merge(int *array, size_t size, int up)
{

	size_t mid = size / 2;
	size_t s;
	size_t f;

	if (size > 1)
	{
		for (s = 0; s < mid; s++)
		{
			if ((array[s] > array[s + mid]) == up)
			{
				swap(&array[s], &array[s + mid]);
				printf("Merging [%d/%d] (%s):\n", (int)s, (int)size, up ? "UP" : "DOWN");
			for (f = 0; f < size; f++)
				printf("%d%s", array[f], f == size - 1 ? "\n" : ", ");
			}
		}

		bitonic_merge(array, mid, up);
		bitonic_merge(array + mid, mid, up);
	}
}

/**
* bitonic_sort_recursive - Sorts a bitonic sequence recursively
* @array: Array to sort
* @size: Array size
* @up: 1 for ascending order, 0 for descending order merge
*/
void bitonic_sort_recursive(int *array, size_t size, int up)
{
	size_t mid = size / 2;

	if (size > 1)
	{
		bitonic_sort_recursive(array, mid, 1);
		bitonic_sort_recursive(array + mid, mid, 0);

		bitonic_merge(array, size, up);
	}
}

/**
* bitonic_sort - BitonicSorts an array
* @array: Array to sort
* @size: Array size (in the power of 2)
*/
void bitonic_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 1);
}
