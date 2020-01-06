#include "monty.h"
/**
 * _pchar - put char.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	err_ascii(&(*stack), line_number);
	printf("%c\n", (*stack)->n);
}
/**
 * _pstr - print string.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp && tmp->n > 0)
	{
		if (tmp->n > 64 && tmp->n < 128)
			putchar(tmp->n);
		if (!tmp->next)
			putchar('\n');
		tmp = tmp->next;
	}
}
