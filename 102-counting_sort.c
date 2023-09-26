#include "sort.h"

/**
 * find_max - This looks for the maximum value in an array of integers.
 * @array: This is the array of integers.
 * @size: This is the size of the array.
 *
 * Return: maximum value.
 */
int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t a;

	for (a = 1; a < size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}
	return (max);
}

/**
 * counting_sort - This sorts array of ints using Counting Sort.
 * @array: This is the array of integers.
 * @size: This is the size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max_value;
	int *count;
	int *output;
	size_t a;

	if (array == NULL || size < 2)
		return;
	max_value = find_max(array, size);
	count = malloc(sizeof(int) * (max_value + 1));
	if (count == NULL)
		return;
	for (a = 0; a <= (size_t)max_value; a++)
		count[a] = 0;
	for (a = 0; a < size; a++)
		count[array[a]]++;
	for (a = 1; a <= (size_t)max_value; a++)
		count[a] += count[a - 1];
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (a = size - 1; ; a--)
	{
		output[count[array[a]] - 1] = array[a];
		count[array[a]]--;
		if (a == 0)
			break;
	}
	for (a = 0; a < size; a++)
		array[a] = output[a];
	for (a = 0; a <= (size_t)max_value; a++)
	{
		if (a == 0)
			printf("%d", count[a]);
		else
			printf(", %d", count[a]);
	}
	printf("\n");
	free(count);
	free(output);
}
