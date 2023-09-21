#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm
 * @list: pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			prev->next = next;
			prev = current->prev;
			print_list(*list);
		}
		current = next;
	}
}
