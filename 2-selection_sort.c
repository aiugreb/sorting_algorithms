#include "sort.h"
/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: pointer to the array to be sorted
 * @size: number of element in the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int swap;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap = array[i];
			array[i] = array[min];
			array[min] = swap;
			print_array(array, size);
		}
	}
}
