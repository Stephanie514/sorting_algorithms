#include "sort.h"

/**
 * swap_node - Swaps two doublylinked_list nodes
 * @list: Double pointer to head of doubly linked list
 * @left: Points to left node
 * @right: Points to right node
 */
void swap_node(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;

	print_list(*list);
}

/**
 * cocktail_sort_list - Cocktail_shaker sorts a doublylinked_list
 * @list: Double pointer to head of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swappdNode;
	listint_t *links, *rechts;/*left and right respectively*/

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swappdNode = 0;
		links = *list;

		while (links->next != NULL)
		{
			rechts = links->next;
			if (links->n > rechts->n)
			{
				swap_node(list, links, rechts);
				swappdNode = 1;
			}
			else
				links = links->next;
		}
		if (swappdNode == 0)
			break;

		swappdNode = 0;
		rechts = links;
		while (rechts->prev != NULL)
		{
			links = rechts->prev;
			if (links->n > rechts->n)
			{
				swap_node(list, links, rechts);
				swappdNode = 1;
			}
			else
				rechts = rechts->prev;
		}
	} while (swappdNode);
}
