#include "sort.h"
#include <stdio.h>

/**
 * _partition -  Partitions an array of integers around a pivot
 * using the Lomuto partition scheme
 * @array: Pointer to a pointer to the first element of the integer array
 * @down: Starting index of the partitioning range
 * @up: Ending index of the partitioning range
 * @size: Size of the array
 *
 * Return: index point
 */
size_t _partition(int **array, size_t down, size_t up, size_t size)
{
	size_t i, j;
	int temp, pivot;

	pivot = (*array)[up];
	i = down - 1;
	for (j = down; j < up; j++)
	{
		if ((*array)[j] <= pivot)
		{
			i++;
			temp = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = temp;
			if ((*array)[i] !=  (*array)[j])
				print_array(*array, size);
		}
	}

	temp =  (*array)[i + 1];
	(*array)[i + 1] = (*array)[up];
	(*array)[up] = temp;
	if ((*array)[i + 1] !=  (*array)[up])
		print_array(*array, size);
	return (i + 1);
}

/**
 * _sort - Recursive function to implement the QuickSort algorithm
 * @array: Pointer to a pointer to the first element of the integer array
 * @down: starting index of the current partitioning range
 * @up:  Ending index of the current partitioning range
 * @size: size of the array
 *
 * Return: none
 */
void _sort(int **array, size_t down, size_t up, size_t size)
{
	size_t d;

	if (down < up)
	{
		d = _partition(array, down, up, size);

		if (d != 0)
			_sort(array, down, (d - 1), size);
		if (d < size - 1)
			_sort(array, (d + 1), up, size);
	}
}

/**
 * quick_sort - Sorts an array of integers
 * @array: element of the integer array
 * @size: size of array
 *
 * Return: none
 */

void quick_sort(int *array, size_t size)
{
	if (size > 1)
		_sort(&array, 0, (size - 1), size);
}
