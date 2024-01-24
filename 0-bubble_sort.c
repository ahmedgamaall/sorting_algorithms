#include "sort.h"
/**
 * bubble_sort - sorts an array of integers
 * using the Bubble sort algorithm
 *
 * @array: array of numbers
 * @size: size of array
 *
 * returns: no return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, fg;
	int t;

	for (i = 0; i < size; i++)
	{
		fg = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;

				print_array(array, size);
				fg = 1;
			}
		}
		if (!fg)
			break;
	}
}
