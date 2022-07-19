#include "sort.h"
void swap(listint_t **list, listint_t **big1, listint_t **small1);
/**
 * cocktail_sort_list - cocktail shaker
 * @list: list
 * Returns: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tc, *small, *big;
	int sorted = 1;

	if ((*list)->next == NULL)
		return;
	while (sorted != 0)
	{
		sorted = 0;
		current = *list;
		while (current)
		{
			if (current->next && current->next->n < current->n)
			{
				small = current->next;
				big = current;
				swap(&*list, &big, &small);
				sorted = 1;
			}
			else
			{
				tc = current;
				current = current->next;
			}
		}
		current = tc->prev;
		while (current)
		{
			if (current->prev && current->prev->n > current->n)
			{
				small = current;
				big = current->prev;
				swap(&*list, &big, &small);
				sorted = 1;
			}
			else
				current = current->prev;
		}
	}
}
/**
 * swap - swap two nodes
 *
 * @list : list
 * @big1 : node with bigger n
 * @small1 : node with smaller n
 * Returns: void
 */
void swap(listint_t **list, listint_t **big1, listint_t **small1)
{
	listint_t *small, *big;

	small = *small1;
	big = *big1;

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
	print_list(*list);
}
