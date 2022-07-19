#include "sort.h"

void merge_sorthelp(int *array, int *temp, int low, int high);
void merge(int *arr, int *temp, int low, int mid, int high);
/**
 * merge_sort - try to merge sort
 * @array : array
 * @size  : size
 * Returns: void
 */
void merge_sort(int *array, size_t size)
{
	int sizet = (int)size;
	int *temp;

	temp = malloc(sizeof(int) * (size));
	merge_sorthelp(array, temp, 0, sizet - 1);
	free(temp);
}
/**
 * merge_sorthelp - trying merge sort
 * @array : array
 * @low : low index
 * @high : high index
 * @temp : temp array
 * Returns: void
 */
void merge_sorthelp(int *array, int *temp, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = low + (high - low) / 2;
		if ((mid - low) == (high - mid))
			mid = mid - 1;

		merge_sorthelp(array, temp, low, mid);
		merge_sorthelp(array, temp, mid + 1, high);
		merge(array, temp, low, mid, high);
	}
}
/**
 * merge - merging function
 * @arr : arr
 * @low : low index
 * @mid : mid index
 * @high: high index
 * @temp : temp array
 * Returns: void
 */
void merge(int *arr, int *temp, int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low, n;

	printf("Merging...\n[left]: ");
	print_array(arr + low, (size_t)(mid - low + 1));
	printf("[right]: ");
	print_array(arr + j, (size_t)(high - mid));
	printf("[Done]: ");
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= high)
		temp[k++] = arr[j++];
	print_array(temp + low, (high - low + 1));
	for (n = low; n <= high; n++)
		arr[n] = temp[n];
}
