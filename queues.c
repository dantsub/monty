#include "monty.h"
/**
 * _pall - print element (n) of stack.
 *  @stack: stack.
 *  @line_number: void.
 *  Return: Nothing.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{	printf("%d\n", (*stack)->n);
		_pall(&(*stack)->next, line_number);
	}
}
/**
 * _pint - pint
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
		err_line(line_number, "pint", 2);
	printf("%d\n", (*stack)->n);
}
/**
 * _pop - pop
 * @stack: stack
 * @line_number: line_number.
 * Return: Nothing.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;

	if (!(*stack))
		err_line(line_number, "pop", 3);
	if ((*stack)->next)
		(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(actual);
}
/**
 * _swap - swap
 * @stack: stack
 * @line_number: line_number.
 * Return: Nothing.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int swap;

	if (!*stack || !(*stack)->next)
		err_line(line_number, "add", 4);

	swap = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swap;
}
