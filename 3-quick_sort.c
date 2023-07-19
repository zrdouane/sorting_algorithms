#include "sort.h"

/**
 * partition - Partitions an array around a pivot element
 * @array: Pointer to the array
 * @first: Index of the first element of the partition
 * @last: Index of the last element of the partition
 * @size: Size of the array
 *
 * Description: Implements the partition step of the quicksort algorithm.
 * The function selects a pivot element from the array and partitions the
 * elements around the pivot such that all elements to the left of the pivot
 * are smaller and all elements to the right are larger. The function returns
 * the final position of the pivot element after the partitioning.
 *
 * Return: Final position of the pivot element
 */
int partition(int *array, int first, int last, size_t size)
{
	int i = first - 1, aux, k;

	for (k = first; k <= last - 1; k++)
	{
		if (array[k] < array[last])
		{
			i++;
			if (i < k)
			{
				aux = array[i];
				array[i] = array[k];
				array[k] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[last])
	{
		aux = array[i + 1];
		array[i + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the quicksort algorithm
 * @array: Pointer to the array
 * @first: Index of the first element of the array/subarray
 * @last: Index of the last element of the array/subarray
 * @size: Size of the array
 *
 * Description: Implements the quicksort algorithm to sort the given
 * array in ascending order. The function selects a pivot element from
 * the array and partitions the elements around the pivot. It then
 * recursively applies the quicksort algorithm to the subarrays formed
 * on either side of the pivot until the entire array is sorted.
 *
 * Return: None
 */
void quicksort(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		quicksort(array, first, pivot - 1, size);
		quicksort(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Description: Implements the quicksort algorithm to sort the given
 * array in ascending order. The function calls the auxiliary function
 * quicksort to perform the actual sorting by specifying the range of
 * indices from 0 to size - 1.
 *
 * Return: None
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
