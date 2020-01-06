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

	if (!(global->new_n) || !_isdigit())
		err_line(line_number, "push", 1);

	elem = malloc(sizeof(stack_t));
	err_malloc(elem);

	if (!*stack)
		elem->next = NULL;
	else
	{	elem->next = *stack;
		(*stack)->prev = elem;
	}
	elem->n = atoi(global->new_n);
	elem->prev = NULL;
	*stack = elem;
}
