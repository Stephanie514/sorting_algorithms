#include "sort.h"
/**
 * counting_sort - Sorts an array using Counting Sort
 * @array: Array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int maximum = array[0];
	size_t s;
	int *tally, *sortd;
	ssize_t f;

	if (array == NULL || size < 2)
		return;
	for (s = 0; s < size; s++)
	{
		if (array[s] > maximum)
			maximum = array[s];
	}
	tally = malloc((maximum + 1) * sizeof(int));
	if (tally == NULL)
		return;
	for (s = 0; s <= (size_t)maximum; s++)
		tally[s] = 0;
	for (s = 0; s < size; s++)
		tally[array[s]]++;
	for (s = 1; s <= (size_t)maximum; s++)
		tally[s] += tally[s - 1];

	sortd = malloc(size * sizeof(int));
	if (sortd == NULL)
	{
		free(tally);
		return;
	}
	for (f = size - 1; f >= 0; f--)
	{
		sortd[tally[array[f]] - 1] = array[f];
		tally[array[f]]--;
	}
	for (s = 0; s < size; s++)
		array[s] = sortd[s];
	printf("Counting array:\n");
	for (s = 0; s <= (size_t)maximum; s++)
		printf("%d%s", tally[s], (s < (size_t)maximum) ? ", " : "\n");
	free(tally);
	free(sortd);
}
