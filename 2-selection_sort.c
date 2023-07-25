#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: the array
 * @size: thae size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, t, k;

	for (i = 0; i < size - 1; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[k])
				k = j;

		if (k != i)
		{
			t = array[i];
			array[i] = array[k];
			array[k] = t;

			print_array(array, size);
		}
	}
}
