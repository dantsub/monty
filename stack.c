#include "monty.h"
/**
 * _push - Insert a new item at the beginning of the stack.
 * @stack: stack.
 * @line_number: void.
 * Return: Nothing.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *elem;
	(void)line_number;

	elem = malloc(sizeof(stack_t));
	err_malloc(elem);
	if (!*stack)
		elem->next = NULL;
	else
	{	elem->next = *stack;
		(*stack)->prev = elem;
	}
	elem->n = number;
	elem->prev = NULL;
	*stack = elem;
}
