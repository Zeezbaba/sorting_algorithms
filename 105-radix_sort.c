#include "sort.h"

int _maxFinder(int *array, int size);
void _radixSorting(int *array, size_t size, int rads, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * _maxFinder - Finds the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int _maxFinder(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}

/**
 * _radixSorting - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @rads: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void _radixSorting(int *array, size_t size, int rads, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / rads) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / rads) % 10] - 1] = array[i];
		count[(array[i] / rads) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, rads, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	maximum = _maxFinder(array, size);
	for (rads = 1; maximum / rads > 0; rads *= 10)
	{
		_radixSorting(array, size, rads, buffer);
		print_array(array, size);
	}

	free(buffer);
}
