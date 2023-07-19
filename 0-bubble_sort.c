#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Description: Implements the bubble sort algorithm to sort
 * the given array in ascending order.
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
	size_t index;
	size_t x;
	int tempo;

	if (array == NULL || size < 2)
		return;

	for (index = 0; index < size - 1; index++)
		for (x = 0; x < size - 1 - index; x++)
			if (array[x] > array[x + 1])
			{
				tempo = array[x + 1];
				array[x + 1] = array[x];
				array[x] = tempo;
				print_array(array, size);
			}
}
