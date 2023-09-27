#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of ints
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *crrnt, *temp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	crrnt = (*list)->next;

	while (crrnt != NULL)
	{
		temp = crrnt;
		prev = crrnt->prev;

		while (prev != NULL && prev->n > temp->n)
		{
			prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = prev;
			temp->prev = prev->prev;
			temp->next = prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->prev = temp;
			prev = temp->prev;
			print_list(*list);
		}

		crrnt = crrnt->next;
	}
}
