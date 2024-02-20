#include "sort.h"

/**
 * insertion_sort_list - sorts a list using insertion sort
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Return: Always 0 (Success)
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *insert, *previous, *temp;
	int n;

	if (!list || !*list || !(*list)->next)
		return;
	previous = *list;
	insert = previous->next;
	while (insert)
	{
		n = insert->n;
		temp = insert->next;
		while (previous && n < previous->n)
		{
			if (n < previous->n)
			{
				if (previous->prev)
					previous->prev->next = insert;
				insert->prev = previous->prev;
				previous->next = insert->next;
				previous->prev = insert;
				if (insert->next)
					insert->next->prev = previous;
				insert->next = previous;
				previous = insert->prev;
				if (!previous)
					*list = insert;
				print_list(*list);
			}
			else
				break;
		}
		insert = temp;
		if (!insert)
			break;
		previous = insert->prev;
	}
}
