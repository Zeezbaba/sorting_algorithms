#include "sort.h"

void _swapIntegers(int *num1, int *num2);
void _bitonicMerger(int *array, size_t size, size_t head, size_t seq,
		char dir);
void _bitonicDir(int *array, size_t size, size_t head, size_t seq, char dir);
void bitonic_sort(int *array, size_t size);

/**
 * _swapIntegers - Swap two integers in an array.
 * @num1: The first integer to swap.
 * @num2: The second integer to swap.
 */
void _swapIntegers(int *num1, int *num2)
{
	int swapper;

	swapper = *num1;
	*num1 = *num2;
	*num2 = swapper;
}

/**
 * _bitonicMerger - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @head: The beginning index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @dir: The direction to sort in.
 */
void _bitonicMerger(int *array, size_t size, size_t head, size_t seq,
		char dir)
{
	size_t i, skip = seq / 2;

	if (seq > 1)
	{
		for (i = head; i < head + skip; i++)
		{
			if ((dir == UP && array[i] > array[i + skip]) ||
			    (dir == DOWN && array[i] < array[i + skip]))
				_swapIntegers(array + i, array + i + skip);
		}
		_bitonicMerger(array, size, head, skip, dir);
		_bitonicMerger(array, size, head + skip, skip, dir);
	}
}

/**
 * _bitonicDir - Translate an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @head: The front index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @dir: The direction to sort the bitonic sequence block in.
 */
void _bitonicDir(int *array, size_t size, size_t head, size_t seq, char dir)
{
	size_t skip = seq / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + head, seq);

		_bitonicDir(array, size, head, skip, UP);
		_bitonicDir(array, size, head + skip, skip, DOWN);
		_bitonicMerger(array, size, head, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + head, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_bitonicDir(array, size, 0, size, UP);
}
