#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * of integers in ascending order
 * @list: Double pointer to the head of the list
 *
 * Description: Implements the insertion sort algorithm to sort
 * the given doubly linked list in ascending order. The function
 * iterates through the list, comparing each node with its previous
 * node and swapping them if they are in the wrong order. The process
 * is repeated until the entire list is sorted.
 *
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pointer, *temporary;

	if (!list)
		return;

	pointer = *list;

	while (pointer)
	{
		while (pointer->next && (pointer->n > pointer->next->n))
		{
			temporary = pointer->next;
			pointer->next = temporary->next;
			temporary->prev = pointer->prev;

			if (pointer->prev)
				pointer->prev->next = temporary;

			if (temporary->next)
				temporary->next->prev = pointer;

			pointer->prev = temporary;
			temporary->next = pointer;

			if (temporary->prev)
				pointer = temporary->prev;
			else
				*list = temporary;

			print_list(*list);
		}
		pointer = pointer->next;
	}
}
