#include "sort.h"
int len_list(listint_t *h);
/**
 * insertion_sort_list - insert sort list
 * @list: list
 * Returns: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *small, *big;

	current = *list;
	if (!list || !(*list) || len_list(*list) < 2)
		return;
	while (current)
	{
		if (current->prev && current->prev->n > current->n)
		{
			small = current;
			big = current->prev;

			if (big->prev != NULL)
			{
				small->prev = big->prev;
				big->prev->next = small;
			}
			else
			{
				small->prev = NULL;
				*list = small;
			}
			if (small->next)
			{
				small->next->prev = big;
			}
			big->next = small->next;
			small->next = big;
			big->prev = small;
			current = small;
			print_list(*list);
		}
		else
			current = current->next;
	}
}
/**
 * len_list - returns the length of a linked list
 * @h: pointer to the list
 *
 * Return: length of list
 */
int len_list(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}
