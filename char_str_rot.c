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

	if (tmp && tmp->n > 0 && tmp->n < 127)
	{
		while (tmp && tmp->n < 127 && tmp->n > 0)
		{
			if (tmp->n > 64 && tmp->n < 127)
				putchar(tmp->n);
			tmp = tmp->next;
		}
		putchar('\n');
	}
}
