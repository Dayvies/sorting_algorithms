#include "sort.h"
/**
 * selection_sort - selection sort of integers
 *
 * @array: array
 * @size: size of array
 * Returns: Void
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, jmin;
	int temp;

	if ((int)size < 3)
		return;

	for (i = 0; i < size - 1; i++)
	{
		jmin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jmin])
			{
				jmin = j;
			}
		}
		if (jmin != i)
		{
			temp = array[i];
			array[i] = array[jmin];
			array[jmin] = temp;
			print_array(array, size);
		}
	}
}
