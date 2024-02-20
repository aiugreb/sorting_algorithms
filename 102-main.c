#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	counting_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}

/*
 *
 *loop throughinput  array get max number
 *	create count array[max+1] initlise to 0
 *		loop through input array
 *			each value in input array
 *			use it as index in count array to inc++
 *		loop through count array
 *			add the previos value to the next index
 *		create new array same lenght as input
 *			loop through input
 *				each value copy it to :
 *					new_array[count_array[array[i]]-1]
 *		copy new array to input array
 */
