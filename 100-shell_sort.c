#include "sort.h"
/**
 * shell_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: index of the start
 * Return: Nothing
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i = 0;
	int j = 0, k = 0, temp;

	if (!array || size < 2)
		return;
	while (gap <= size)
		gap = gap * 3 + 1;
	for (gap = (gap - 1) / 3; gap > 1; gap = (gap - 1) / 3)
	{
		for (i = 0; i + gap < size; i++)
		{
			if (array[i] > array[i + gap])
			{
				for (j = i + gap, k = i; j >= 0 && k >= 0 && array[k] > array[j];
					 j = j - gap, k = k - gap)
				{
					temp = array[j];
					array[j] = array[k];
					array[k] = temp;
				}
			}
		}
		print_array(array, size);
	}
	for (i = 1; i < size; i++)
	{
		if (array[i - 1] > array[i])
		{
			for (j = i - 1, k = i; j >= 0 && array[k] < array[j]; j--, k--)
			{
				temp = array[k];
				array[k] = array[j];
				array[j] = temp;
			}
		}
	}
	print_array(array, size);
}
