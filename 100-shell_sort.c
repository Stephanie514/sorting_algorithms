#include "sort.h"

/**
 * shell_sort - This function sorts an array of integers
 * in ascending order using shell sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t space = 1, a, b;
	int var;
	int *sorted_array;

	if (array == NULL || size < 2)
		return;
	while (space < size / 3)
		space = space * 3 + 1;
	while (space > 0)
	{
		for (a = space; a < size; a++)
		{
			var = array[a];
			b = a;
			while (b >= space && array[b - space] > var)
			{
				array[b] = array[b - space];
				b -= space;
			}
			array[b] = var;
		}
		sorted_array = malloc(sizeof(int) * size);

		if (sorted_array == NULL)
			return;
		for (a = 0; a < size; a++)
			sorted_array[a] = array[a];
		print_array(sorted_array, size);
		free(sorted_array);
		space = (space - 1) / 3;
	}
}
