#include "sort.h"

/**
 * _swapIntegers - Swap two integers in an array.
 * @i: The first integer.
 * @j: The second integer.
 */
void _swapIntegers(int *i, int *j)
{
	int swp;

	swp = *i;
	*i = *j;
	*j = swp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, lenght = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (i = 0; i < lenght - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				_swapIntegers(array + i, array + i + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		lenght--;
	}
}
