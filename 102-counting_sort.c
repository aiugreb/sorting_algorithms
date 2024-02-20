#include "sort.h"

/**
 * counting_sort - Entry point
 * @array: The character to print
 * @size: The character to print
 * Return: -
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *new_array, max = 0, i = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	count_array = malloc(sizeof(int) * max + 1);
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= max; i++)
		count_array[i] = count_array[i - 1] + count_array[i];
	new_array = malloc(sizeof(int) * size + 1);
	print_array(count_array, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		new_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];
}
