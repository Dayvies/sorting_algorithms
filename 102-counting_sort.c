#include "sort.h"

/**
 * counting_sort - sort using counting method
 * @array : array
 * @size  :size
 * Returns : void
 */
void counting_sort(int *array, size_t size)
{
	int *carr, *out;
	int max = array[0], i;
	int sizet;

	if (!size || (int)size < 2)
		return;
	sizet = (int)size;
	for (i = 1; i < sizet; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	carr = (int *)malloc(sizeof(int) * (max + 1));
	out = (int *)malloc(sizeof(int) * (size));
	for (i = 0; i <= max; i++)
		carr[i] = 0;
	for (i = 0; i < sizet; i++)
		carr[array[i]]++;
	for (i = 0; i <= max; i++)
		carr[i] += carr[i - 1];
	print_array(carr, (size_t)(max + 1));
	for (i = (int)size - 1; i >= 0; i--)
	{
		out[carr[array[i]] - 1] = array[i];
		carr[array[i]]--;
	}
	for (i = 0; i < sizet; i++)
	{
		array[i] = out[i];
	}

	free(carr);
	free(out);
}
