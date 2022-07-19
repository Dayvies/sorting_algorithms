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
	int array[] = {85, 138, 161, 132, 132, 162, 25, 59, 117, 176, 194, 132, 180, 140, 98, 56, 97, 143, 198, 64, 92, 81};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	merge_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}