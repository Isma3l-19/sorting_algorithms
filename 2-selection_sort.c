#include "sort.h"
/**
 * swap_ints - function that swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * selection_sort - sorts an array of integers in ascending
 * order using selection algorithm
 * @array: array of integers
 * @size: size of array
 * Description: prints array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *arr;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		arr = array + i;
		for (j = i + 1; j < size; j++)
		{
			arr = (array[j] < *arr) ? (array + j) : arr;
		}
		if ((array + i) != arr)
		{
			swap_ints(array + i, arr);
			print_array(array, size);
		}
	}
}
