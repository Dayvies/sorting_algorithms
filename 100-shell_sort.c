#include "sort.h"

/**
 * shell_sort- shell sort using knuth
 * @size: size of array
 * @array: array
 * Returns: void
 */
void shell_sort(int *array, size_t size)
{
	int in, out, vins, inter = 1;
	int sizet, i = 0;

	if (!size || (int)size < 2)
		return;
	sizet = (int)size;
	while (inter <= sizet / 3)
		inter = inter * 3 + 1;
	while (inter > 0)
	{
		for (out = inter; out < sizet; out++)
		{
			vins = array[out];
			in = out;
			while (in > inter - 1 && array[in - inter] >= vins)
			{
				array[in] = array[in - inter];
				in -= inter;
			}
			array[in] = vins;
		}
		inter = (inter - 1) / 3;
		print_array(array, size);
		i++;
	}
}
