#include "sort.h"

void _headnodeSwap(listint_t **list, listint_t **tail, listint_t **swapper);
void _tailnodeSwap(listint_t **list, listint_t **tail, listint_t **swapper);
void cocktail_sort_list(listint_t **list);

/**
 * _headnodeSwap - Swap a node in a doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @swapper: A pointer to the current swapping node of the cocktail algorithm.
 */
void _headnodeSwap(listint_t **list, listint_t **tail, listint_t **swapper)
{
	listint_t *swp = (*swapper)->next;

	if ((*swapper)->prev != NULL)
		(*swapper)->prev->next = swp;
	else
		*list = swp;
	swp->prev = (*swapper)->prev;
	(*swapper)->next = swp->next;
	if (swp->next != NULL)
		swp->next->prev = *swapper;
	else
		*tail = *swapper;
	(*swapper)->prev = swp;
	swp->next = *swapper;
	*swapper = swp;
}

/**
 * _tailnodeSwap - Swap a node in a doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @swapper: A pointer to the current swapping node of the cocktail algorithm.
 */
void _tailnodeSwap(listint_t **list, listint_t **tail, listint_t **swapper)
{
	listint_t *swp = (*swapper)->prev;

	if ((*swapper)->next != NULL)
		(*swapper)->next->prev = swp;
	else
		*tail = swp;
	swp->next = (*swapper)->next;
	(*swapper)->prev = swp->prev;
	if (swp->prev != NULL)
		swp->prev->next = *swapper;
	else
		*list = *swapper;
	(*swapper)->next = swp;
	swp->prev = *swapper;
	*swapper = swp;
}

/**
 * cocktail_sort_list - Sort a doubly-linked list of integers in
 *                      ascending order using the cocktail algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *swapper;
	bool shaker = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaker == false)
	{
		shaker = true;
		for (swapper = *list; swapper != tail; swapper = swapper->next)
		{
			if (swapper->n > swapper->next->n)
			{
				_headnodeSwap(list, &tail, &swapper);
				print_list((const listint_t *)*list);
				shaker = false;
			}
		}
		for (swapper = swapper->prev; swapper != *list;
				swapper = swapper->prev)
		{
			if (swapper->n < swapper->prev->n)
			{
				_tailnodeSwap(list, &tail, &swapper);
				print_list((const listint_t *)*list);
				shaker = false;
			}
		}
	}
}
