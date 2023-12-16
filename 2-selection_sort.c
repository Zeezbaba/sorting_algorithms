#include "sort.h"

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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *select;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		select = array + i;
		for (j = i + 1; j < size; j++)
			select = (array[j] < *select) ? (array + j) : select;

		if ((array + i) != select)
		{
			_swapIntegers(array + i, select);
			print_array(array, size);
		}
	}
}
