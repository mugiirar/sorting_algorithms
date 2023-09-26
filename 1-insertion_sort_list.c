#include "sort.h"
/**
 * insertion_sort_list - sorting a doubly linked list
 * @list: the list supplied 
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *point;

	if (list == NULL || (*list)->next == NULL)
		return;
	point = (*list)->next;
	while (point != NULL)
	{
		while ((point->prev) && (point->prev->n > point->n))
		{
			point = swap_node(point, list);
			print_list(*list);
		}
		point = point->next;
	}
}
/**
 *swap_node - swap a node helper
 *@node: node
 *@list: node list
 *Return: return pointer of current node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
    listint_t *previous = node->prev;
    listint_t *next = node->next;

    if (previous)
        previous->next = next;
    if (next)
        next->prev = previous;

    node->next = previous;
    node->prev = previous ? previous->prev : NULL;

    if (previous)
        previous->prev = node;
    if (node->prev)
        node->prev->next = node;
    else
        *list = node;

    return node;
}

