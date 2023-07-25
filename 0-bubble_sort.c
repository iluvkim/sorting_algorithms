#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: an array of integers
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int sw = 1;
	size_t i, t, s = size;

	while (sw)
	{
		sw = 0;
		for (i = 1; i < s; i++)
		{
			if (array[i - 1] > array[i])
			{
				t = array[i - 1];
				array[i - 1] = array[i];
				array[i] = t;

				sw = 1;
				print_array(array, size);
			}
		}
		s--;
	}
}
