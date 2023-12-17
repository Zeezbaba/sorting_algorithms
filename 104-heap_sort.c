#include "sort.h"

void _swapIntegers(int *num1, int *num2);
void _heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * _heapify - Function that Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void _heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		_swapIntegers(array + root, array + large);
		print_array(array, size);
		_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int idx;

	if (array == NULL || size < 2)
		return;

	for (idx = (size / 2) - 1; idx >= 0; idx--)
		_heapify(array, size, size, idx);

	for (idx = size - 1; idx > 0; idx--)
	{
		_swapIntegers(array, array + idx);
		print_array(array, size);
		_heapify(array, size, idx, 0);
	}
}
