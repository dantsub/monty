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

	while (tmp && tmp->n > 0 && tmp->n < 127)
	{
		if (tmp->n > 64 && tmp->n < 127)
			putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
/**
 * _rotl - rotates the stack to the top.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *change;
	int n;
	(void)line_number;

	if (tmp)
	{
		change = tmp->next;
		n = tmp->n;
		while (tmp->next)
		{
			tmp->n = change->n;
			tmp = change;
			change = tmp->next;
		}
		tmp->n = n;
	}
}
/**
 * _rotr - rotates the stack to the bottom.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (tmp && tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		_ps(&(*stack), tmp->next->n);
		free(tmp->next);
		tmp->next = NULL;
	}
}
