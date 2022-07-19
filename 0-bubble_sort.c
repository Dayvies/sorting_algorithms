#include "sort.h"
/**
 * bubble_sort - buble sorts
 * @array: array to be sorted
 * @size: size of Array sorted
 * Returns: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int j, i;
	int temp;

	if (size <= 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
