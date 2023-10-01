#include "sort.h"
/**
* get_max - Fx fetches maximum value in an array
* @array: Array to search
* @size: Array size
* Return: Maximum value.
*/
int get_max(int *array, size_t size)
{
	int maximum_val = array[0];
	size_t y;

	for (y = 1; y < size; y++)
	{
		if (array[y] > maximum_val)
			maximum_val = array[y];
	}

	return (maximum_val);
}
/**
* count_sort - Sort the array based on the lsd digit
* @array: Array to sort
* @size: Array size
* @lsd: Least Signifigant digit currently being considered
* Return: sorted array
*/
void count_sort(int *array, size_t size, int lsd)
{
	int *sorted_array = malloc(sizeof(int) * size);
	int tally[10] = {0};
	int y;

	if (!sorted_array)
		return;

	for (y = 0; y < (int)size; y++)
		tally[(array[y] / lsd) % 10]++;

	for (y = 1; y < 10; y++)
		tally[y] += tally[y - 1];

	for (y = size - 1; y >= 0; y--)
	{
		sorted_array[tally[(array[y] / lsd) % 10] - 1] = array[y];
		tally[(array[y] / lsd) % 10]--;
	}

	for (y = 0; y < (int)size; y++)
		array[y] = sorted_array[y];

	free(sorted_array);
}

/**
* radix_sort - sorts an array using Radix sort
* @array: Array to sort
* @size: Array size
*/
void radix_sort(int *array, size_t size)
{
	int maximum = get_max(array, size);
	int lsd;

	for (lsd = 1; maximum / lsd > 0; lsd *= 10)
	{
		count_sort(array, size, lsd);
		print_array(array, size);
	}
}
