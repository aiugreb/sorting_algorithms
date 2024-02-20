#include "sort.h"
/**
 * swap - simple function to swap two values
 * @a: First element
 * @b: Second element
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - function to correct position of the pivot
 * @array: pointer to array
 * @low: index of the start
 * @high: index of the end
 * @size: array size
 * Return: Nothing
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		print_array(array, size);
	return (i + 1);
}
/**
 * quick_sort_recursion - function helper to do sort subarrays
 * @array: array of integers
 * @low: index of the start
 * @high: index of the end
 * @size: array size
 * Return: Nothing
 */
void quick_sort_recursion(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		if (pivot_index > 1)
			quick_sort_recursion(array, low, pivot_index - 1, size);
		if (high > 1)
			quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - function to perform quick sort algorithm
 * @array: pointer to array of integers
 * @size: number of element in the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}
