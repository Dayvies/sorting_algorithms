#include "sort.h"

void quickSort(int *arr, int low, int high, size_t size);
int partition(int *arr, int low, int high, size_t size);
/**
 * quick_sort - calls quick_sort
 * @array : array
 * @size  : size of array
 * Returns: void
 */
void quick_sort(int *array, size_t size)
{
	int sizet;

	if (!size || (int)size < 2)
		return;
	sizet = (int)size;
	quickSort(array, 0, sizet - 1, size);
}
/**
 * quickSort - quick sort recursively
 * @arr: arr
 * @low: low index
 * @high: high index
 * @size : size
 * Returns: void
 */
void quickSort(int *arr, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);
		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}
/**
 * partition - Lomuto partition
 * @arr : arr
 * @low : low index
 * @high : high index
 * @size : size
 * Return: integer on lomuto partition
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int temp, i = (low - 1), j = 0;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (arr[j] != arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				print_array(arr, size);
			}
		}
	}
	if (arr[i + 1] == arr[high])
		return (i + 1);
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	print_array(arr, size);
	return (i + 1);
}
