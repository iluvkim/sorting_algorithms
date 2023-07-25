#include "sort.h"

/**
 * insertion_sort_list -  Sorts a doubly linked list in ascending order
 * using insertion sort
 * @list: A pointer to a pointer to the first element
 *
 * Return: none
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *c, *h, *p, *q, *r;

	if (list == NULL)
		return;
	if ((*list) == NULL || (*list)->next == NULL)
		return;
	p = *list;
	c = (*list)->next;
	h = *list;
	while (c)
	{
		r = c;
		q = p;
		while (q && q->n > r->n)
		{
			if (q->prev == NULL)
				h = r;
			if (r == c)
				c = q;
			if (r->next != NULL)
				r->next->prev = q;
			if (q->prev != NULL)
				q->prev->next = r;
			r->prev = q->prev;
			q->next = r->next;
			r->next = q;
			q->prev = r;
			q = r->prev;
			print_list(h);
		}
		p = c;
		c = c->next;
	}
	*list = h;
}
