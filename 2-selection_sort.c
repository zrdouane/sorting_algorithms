#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Description: Implements the selection sort algorithm to sort
 * the given array in ascending order. The function iterates through
 * the array and selects the minimum element in the unsorted portion.
 * It then swaps the minimum element with the first unsorted element.
 * This process is repeated until the array is fully sorted.
 *
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
