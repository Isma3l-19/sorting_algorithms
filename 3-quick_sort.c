#include "sort.h"
/**
 * swap_ints - function that swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	*a = tmp;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_partition - function that orders a subset of an array
 * of integers according to the lomuto partion scheme(last elemnt as pivot)
 * @array: array of integers
 * @size: size of array
 * @left: starting index of the subset
 * @right: the ending point
 * Return: final partion index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}
/**
 * lomuto_sort - implements quicksort algorithm through recursion
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the array partition to order
 * @right: ending index of the array partition to order
 * Description: uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending
 *order using the quicksort algorithm
 * @array: array of integers
 * @size: size of array
 * Description: uses the Lomuto partition scheme. Prints
 *the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
