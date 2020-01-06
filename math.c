#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!*stack || !(*stack)->next)
		err_line(line_number, "add", 4);

	sum = (*stack)->n + (*stack)->next->n;
	_pop(&(*stack), line_number);
	(*stack)->n = sum;
}
