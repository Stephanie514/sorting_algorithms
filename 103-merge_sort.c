#include "sort.h"

/**
 * merge - Sorts array using mergesort
 * @array: array to sort
 * @size: array size
 * @l: points to left array
 * @r: points to right array
 **/
void merge(int *array, int *l, int *r, size_t size)
{
	int f = 0, s = 0, n = 0;
	int s_left, s_right;

	s_left = size / 2;
	s_right = size - s_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, s_left);
	printf("[right]: ");
	print_array(r, s_right);

	while (f < s_left && s < s_right)
	{
		if (l[f] < r[s])
			array[n++] = l[f++];
		else
			array[n++] = r[s++];
	}

	while (f < s_left)
		array[n++] = l[f++];

	while (s < s_right)
		array[n++] = r[s++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array
 * @array: points to array
 * @size: array size
 **/
void merge_sort(int *array, size_t size)
{
	size_t middle = 0, y;
	int links[1000];
	int rechts[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	middle = size / 2;

	for (y = 0; y < middle; y++)
		links[y] = array[y];

	for (y = middle; y < size; y++)
		rechts[y - middle] = array[y];

	merge_sort(links, middle);
	merge_sort(rechts, size - middle);
	merge(array, links, rechts, size);
}
