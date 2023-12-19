#include "sort.h"

void _swapIntegers(int *num1, int *num2);
int _hoareRecursive(int *array, size_t size, int high, int low);
void _hoareSorting(int *array, size_t size, int high, int low);
void quick_sort_hoare(int *array, size_t size);

/**
 * _swapIntegers - Swap two integers in an array.
 * @num1: The first integer
 * @num2: The second integer
 */
void _swapIntegers(int *num1, int *num2)
{
	int swapper;

	swapper = *num1;
	*num1 = *num2;
	*num2 = swapper;
}

/**
 * _hoareRecursive - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @high: The starting index of the subset to order.
 * @low: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int _hoareRecursive(int *array, size_t size, int high, int low)
{
	int pivot, start, end;

	pivot = array[low];
	for (start = high - 1, end = low + 1; start < end;)
	{
		do {
			start++;
		} while (array[start] < pivot);
		do {
			end--;
		} while (array[end] > pivot);

		if (start < end)
		{
			_swapIntegers(array + start, array + end);
			print_array(array, size);
		}
	}

	return (start);
}

/**
 * _hoareSorting - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @high: The starting index of the array partition to order.
 * @low: The ending index of the array partition to order.
 */
void _hoareSorting(int *array, size_t size, int high, int low)
{
	int partition;

	if (low - high > 0)
	{
		partition = _hoareRecursive(array, size, high, low);
		_hoareSorting(array, size, high, partition - 1);
		_hoareSorting(array, size, partition, low);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_hoareSorting(array, size, 0, size - 1);
}
