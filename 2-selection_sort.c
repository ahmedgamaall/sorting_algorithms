#include "sort.h"
/**
 * selection_sort - sorts an array of integers 
 * using the Selection sort algorithm.
 *
 * @array: array of numbers
 * @size: size of array
 *
 * returns : nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, other;
	int t;

	for (i = 0; i < size; i++)
	{
		other = i;

		for (j = i; j < size; j++)
		{
			if (array[j] < array[other])
			{
				other = j;
			}
		}
		if (other != i)
		{
			t = array[i];
			array[i] = array[other];
			array[other] = t;
			print_array(array, size);
		}
	}
}
