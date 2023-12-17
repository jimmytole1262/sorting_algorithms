#include "sort.h"

/**
 * insertion_sort_list - function that sort a doubly linked list
 * @list: head of doubly linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *tmp;

	if (!list)
		return;
	while (current)
	{
		while (current->next && current->n > current->next->n)
		{
			tmp = current->next;
			current->next = tmp->next;
			tmp->prev = current->prev;

			if (current->prev)
				current->prev->next = tmp;
			if (tmp->next)
				tmp->next->prev = current;

			current->prev = tmp;
			tmp->next = current;
			if (tmp->prev)
				current = tmp->prev;
			else
				*list = tmp;
			print_list(*list);
		}
	 current = current->next;
	}
}
