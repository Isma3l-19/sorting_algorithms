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
 * bubble_sort - function that sorts integers in an array
 * in ascending order
 * *array: array of integers
 * @size: size of array
 * Description: prints array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
