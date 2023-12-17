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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t temp, i, j;

	if (array == NULL || size < 2)
		return;

	for (temp = 1; temp < (size / 3);)
		temp = temp * 3 + 1;

	for (; temp >= 1; temp /= 3)
	{
		for (i = temp; i < size; i++)
		{
			j = i;
			while (j >= temp && array[j - temp] > array[j])
			{
				_swapIntegers(array + j, array + (j - temp));
				j -= temp;
			}
		}
		print_array(array, size);
	}
}
