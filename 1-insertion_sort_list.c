#include "sort.h"

/**
 * swap - Switch two nodes in a doubly-linked list.
 * @head: pointer to the head of the doubly-linked list.
 * @current: pointer to the current node to swap.
 * @next_node: pointer to next node to swith with current node.
 */
void swap(listint_t **head, listint_t **current, listint_t *next_node)
{
	(*current)->next = next_node->next;
	if (next_node->next != NULL)
		next_node->next->prev = *current;
	next_node->prev = (*current)->prev;
	next_node->next = *current;
	if ((*current)->prev != NULL)
		(*current)->prev->next = next_node;
	else
		*head = next_node;
	(*current)->prev = next_node;
	*current = next_node->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert_at, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		insert_at = i->prev;
		while (insert_at != NULL && i->n < insert_at->n)
		{
			swap(list, &insert_at, i);
			print_list((const listint_t *)*list);
		}
	}
}
