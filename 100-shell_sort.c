#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers
 * using the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: array of numbers
 * @size: size of array
 *
 * return : nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, g, fg;

	g = 1;
	while (g < size)
		g = (g * 3) + 1;
	g = (g - 1) / 3;

	while (g > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = i; j < size - g; j += g)
			{
				if (array[j] > array[j + g])
					swap_numbers(&array[j], &array[j + g]);

				fg = j;
				while (fg >= g)
				{
					if (array[fg] < array[fg - g])
						swap_numbers(&array[fg], &array[fg - g]);
					fg -= g;
				}
			}
		}

		g = (g - 1) / 3;
		print_array(array, size);
	}
}

/**
 * swap_numbers - swap two numbers
 *
 * @n1: first number
 * @n2: second number
 */
void swap_numbers(int *n1, int *n2)
{
	int t = *n1;
	*n1 = *n2;
	*n2 = t;
}
