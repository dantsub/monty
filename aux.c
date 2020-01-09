#include "monty.h"
/**
 * _ps - dds a new node at the beginning.
 * @stack: stack.
 * @n: number of stack.
 * Return: *stack.
 */
stack_t *_ps(stack_t **stack, int n)
{
	stack_t *elem;

	elem = malloc(sizeof(stack_t));
	err_malloc(elem);
	elem->n = n;
	elem->prev = NULL;

	if (!(*stack))
		elem->next = NULL;
	else
	{
		elem->next = *stack;
		(*stack)->prev = elem;
	}
	*stack = elem;
	return (*stack);
}
