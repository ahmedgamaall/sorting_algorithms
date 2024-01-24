#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers using the Insertion sort algorithm.
 *
 * @list: list of numbers
 *
 * returns : nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *c1, *t, *c2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	c1 = (*list)->next;

	while (c1)
	{
		c2 = c1;
		while (c2 != *list && c2->n < c2->prev->n)
		{
			t = c2->prev;
			c2->prev = t->prev;
			if (t->prev)
				t->prev->next = c2;
			t->next = c2->next;
			if (c2->next)
				c2->next->prev = t;

			c2->next = t;
			t->prev = c2;
			if (!c2->prev)
				*list = c2;

			print_list(*list);
			c2 = t->prev;
		}

		c1 = c1->next;
	}
}
