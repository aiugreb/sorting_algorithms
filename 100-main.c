#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	shell_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
/*
*find gap (largest gap les than or equal to size of array)
*loop through gap if gap >  1
*	loop through array (if index+gap is valid)
*	compare index0 with index+Gap
*		if less swap
*		(keep moving to next element)
*	reduce gap
*/
