#include "sort.h"
/**
 * sift_down - Heapify a subtree rooted at given index
 * @array: Array of integers
 * @size: Size of the array
 * @start: Index of the root of the subtree
 * @end: Index of the last element in the heap
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t max_child;
	int temp;

	while (2 * root + 1 <= end)
	{
		max_child = 2 * root + 1;

		if (max_child < end && array[max_child] < array[max_child + 1])
			max_child++;
		if (array[root] < array[max_child])
		{
			temp = array[root];
			array[root] = array[max_child];
			array[max_child] = temp;
			print_array(array, size);
			root = max_child;
		}
		else
			return;
	}
}
/**
 * heap_sort - This sorts array of ints in ascending order using Heap Sort
 * @array: The array to be sorted
 * @size: This is the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
