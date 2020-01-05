#include "monty.h"
/**
 * _pall - print element (n) of stack.
 *  @stack: stack.
 *  @line_number: void.
 *  Return: Nothing.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
	{	printf("%d\n", (*stack)->n);
		_pall(&(*stack)->next, line_number);
	}
}
/**
 * _pint -
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		err_line(line_number, "pint", 2);
	printf("%d\n", (*stack)->n);
}
/**
 * 
 * 
 * 
 * 
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;

	if (!(*stack))
	{
		free_stack(*stack);
		err_line(line_number, "pop", 3);
	}
	if ((*stack)->next)
		(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(actual);
}
