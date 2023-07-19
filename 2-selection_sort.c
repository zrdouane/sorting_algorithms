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
	unsigned int index, tempo;

	if (size < 2)
		return;

	for (index = 0; index < size; index++)
	{
		unsigned int x = index;
		int aux = array[index];

		for (tempo = index + 1; tempo < size; tempo++)
		{
			if (array[tempo] < aux)
				aux = array[tempo], x = tempo;
		}
		if (x != index)
		{
			array[x] = array[index];
			array[index] = aux;
			print_array(array, size);
		}
	}
}
