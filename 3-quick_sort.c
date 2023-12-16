#include "sort.h"

void _swapIntegers(int *num1, int *num2);
int _lomuto(int *array, size_t size, int left, int right);
void _sortLomuto(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * _lomuto - arrange a subset of an array of integers according to
 *                    the lomuto partition scheme
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int _lomuto(int *array, size_t size, int left, int right)
{
	int *tmp, tops, downs;

	tmp = array + right;
	for (tops = downs = left; downs < right; downs++)
	{
		if (array[downs] < *tmp)
		{
			if (tops < downs)
			{
				_swapIntegers(array + downs, array + tops);
				print_array(array, size);
			}
			tops++;
		}
	}

	if (array[tops] > *tmp)
	{
		_swapIntegers(array + tops, tmp);
		print_array(array, size);
	}

	return (tops);
}

/**
 * _sortLomuto - apply the quicksort algorithm through recursion.
 * @array: An array of integers
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void _sortLomuto(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = _lomuto(array, size, left, right);
		_sortLomuto(array, size, left, partition - 1);
		_sortLomuto(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Using the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_sortLomuto(array, size, 0, size - 1);
}
