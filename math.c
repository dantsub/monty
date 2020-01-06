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
/**
 * _sub - subs the top two elements of the stack.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (!*stack || !(*stack)->next)
		err_line(line_number, "sub", 4);

	sub = (*stack)->next->n - (*stack)->n;
	_pop(&(*stack), line_number);
	(*stack)->n = sub;
}
/**
 * _mul - multiplies the top two elements of the stack.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (!*stack || !(*stack)->next)
		err_line(line_number, "mul", 4);

	mul = (*stack)->next->n * (*stack)->n;
	_pop(&(*stack), line_number);
	(*stack)->n = mul;
}
/**
 * _div - divides the top two elements of the stack.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if (!*stack || !(*stack)->next)
		err_line(line_number, "div", 4);
	if ((*stack)->n == 0)
		err_line(line_number, "div", 5);

	div = (*stack)->next->n / (*stack)->n;
	_pop(&(*stack), line_number);
	(*stack)->n = div;
}
/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (!*stack || !(*stack)->next)
		err_line(line_number, "mod", 4);
	if ((*stack)->n == 0)
		err_line(line_number, "mod", 5);

	mod = (*stack)->next->n % (*stack)->n;
	_pop(&(*stack), line_number);
	(*stack)->n = mod;
}
