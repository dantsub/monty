#include "monty.h"
/**
 * _push - Insert a new item.
 * @stack: stack.
 * @line_number: void.
 * Return: Nothing.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *elem;

	if (!(global.new_n) || !(_isdigit()))
		err_line(line_number, "push", 1);

	elem = malloc(sizeof(stack_t));
	err_malloc(elem);
	if (global.change)
		_pstack(&(*stack), elem);
	if (!global.change)
		_pqueue(&(*stack), elem);
}
/**
 * _nop - does nothing.
 * @stack: stack.
 * @line_number: void.
 * Return: Nothing
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * queue_stack - change the way you insert the new item.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void queue_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (!strcmp(global.buff, "queue"))
		global.change = false;
	if (!strcmp(global.buff, "stack"))
		global.change = true;
}
/**
 * _pstack - insert new node at the beginning.
 * @stack: stack.
 * @elem: new node.
 * Return: Nothing.
 */
void _pstack(stack_t **stack, stack_t *elem)
{
	if (!*stack)
		elem->next = NULL;
	else
	{	elem->next = *stack;
		(*stack)->prev = elem;
	}
	elem->n = atoi(global.new_n);
	elem->prev = NULL;
	*stack = elem;
}
