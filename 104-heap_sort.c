#include "sort.h"
void swap(int *a, int *b);
void siftDown(int *arr, int n, int i, int sizet);
/**
 * heap_sort - heap sort
 * @array : array
 * @size : size
 * Returns: void
 */
void heap_sort(int *array, size_t size)
{
	int sizet, h, k;

	if (!size || (int)size < 2)
		return;
	sizet = (int)size;
	for (h = sizet / 2; h >= 0; h--)
		siftDown(array, sizet, h, sizet);
	for (k = sizet - 1; k >= 0; k--)
	{
		if (array[0] != array[k])
		{
			swap(&array[0], &array[k]);
			print_array(array, sizet);
		}
		siftDown(array, k, 0, sizet);
	}
}
/**
 * siftDown - heap trees
 * @n : n
 * @arr : array
 * @i : i
 * @sizet : size
 * Returns: void
 */
void siftDown(int *arr, int n, int i, int sizet)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, sizet);
		siftDown(arr, n, largest, sizet);
	}
}
/**
 * swap - switch two array elements
 * @a : a
 * @b : b
 * Returns: void
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
