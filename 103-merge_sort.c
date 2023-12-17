#include "sort.h"

void _sortMerger(int *array, int *buffer, size_t start, size_t middle,
		size_t end);
void _recursiveSort(int *array, int *buffer, size_t start, size_t end);
void merge_sort(int *array, size_t size);

/**
 * _sortMerger - Sort a subarray of integers.
 * @array: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @start: The start index of the array.
 * @middle: The middle index of the array.
 * @end: The end index of the array.
 */
void _sortMerger(int *array, int *buffer, size_t start, size_t middle,
		size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, middle - start);

	printf("[right]: ");
	print_array(array + middle, end - middle);

	for (i = start, j = middle; i < middle && j < end; k++)
		buffer[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < middle; i++)
		buffer[k++] = array[i];
	for (; j < end; j++)
		buffer[k++] = array[j];
	for (i = start, k = 0; i < end; i++)
		array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * _recursiveSort - Implement the merge sort algorithm through recursion.
 * @array: A subarray of an array of integers
 * @buffer: A buffer to store the sorted result.
 * @start: The start index of the subarray.
 * @end: The end index of the subarray.
 */
void _recursiveSort(int *array, int *buffer, size_t start, size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		_recursiveSort(array, buffer, start, middle);
		_recursiveSort(array, buffer, middle, end);
		_sortMerger(array, buffer, start, middle, end);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	_recursiveSort(array, buffer, 0, size);

	free(buffer);
}
