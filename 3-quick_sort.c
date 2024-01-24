#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: array of numbers
 * @size: size of array
 *
 * return : nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	helper(array, 0, size - 1, size);
}

/**
 * helper - applies the Quick Sort recursively
 *
 * @arr: array of numbers
 * @frt: first element of the partition
 * @lst: last element of the partition
 * @n: size of array
 *
 * return : nothing
 */
void helper(int *arr, int frt, int lst, size_t n)
{
	int pvt_p;

	if (frt < lst)
	{
		pvt_p = part_step(arr, frt, lst, n);
		helper(arr, frt, pvt_p - 1, n);
		helper(arr, pvt_p + 1, lst, n);
	}
}

/**
 * part_step - apply the Quick sort algorithm.
 *
 * @arr: array of numbers
 * @frt: first element of the partition
 * @lst: last element of the partition
 * @n: size of array
 *
 * return : pivot index
 */
int part_step(int arr[], int frt, int lst, size_t n)
{
	int pvt, i, j;

	pvt = arr[lst];
	i = (frt - 1);

	for (j = frt; j <= lst - 1; j++)
	{
		if (arr[j] < pvt)
		{
			i++;
			swap_numbers(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, n);
		}
	}
	if (arr[i + 1] != arr[lst])
	{
		swap_numbers(&(arr[i + 1]), &(arr[lst]));
		print_array(arr, n);
	}
	return (i + 1);
}

/**
 * swap_numbers - swap two numbers
 *
 * @n1: first number
 * @n2: second number
 *
 * return : nothing
 */
void swap_numbers(int *n1, int *n2)
{
	int t = *n1;
	*n1 = *n2;
	*n2 = t;
}
