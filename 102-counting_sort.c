#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The character to print
 * @size: The character to print
 * 
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *new_array, max = 0, i = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	count = malloc(sizeof(int) * max + 1);
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] = count[i - 1] + count[i];
	new_array = malloc(sizeof(int) * size + 1);
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		new_array[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];
}
