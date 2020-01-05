#include "monty.h"
/**
 * err_one_arg - Error if the program does not receive a file
 * or more than one argument.
 * @ac: arguments count.
 * Return: nothing.
 */
void err_one_arg(int ac)
{
	if (ac != 2)
	{	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * err_malloc - print error if there is no memory for the new stack.
 * @n_stack: new stack.
 * Return: nothing.
 */
void err_malloc(stack_t *n_stack)
{
	if (!n_stack)
	{	fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * err_line - Print the error indicating the line where the error is.
 * @line: line number where the error is.
 * @opcd: opcode name.
 * @sel: 0 if no exits opcode, 1 if the opcode exists but it is unduly used.
 * Return: Nothing.
 */
void err_line(unsigned int line, char *opcd, int sel)
{
	(void)opcd;

	switch (sel)
	{
	case 1:
		fprintf(stderr, "L%u: usage: push integer", line);
		break;
	case 2:
		fprintf(stderr, "L%u: can't pint, stack empty", line);
		break;
	case 3:
		fprintf(stderr, "L%u: can't pop an empty stack", line);
		break;
	case 4:
		fprintf(stderr, "L%u: can't %s, stack too short", line, opcd);
		break;
	
	default:
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcd);
		break;
	}
	exit(EXIT_FAILURE);
}
/**
 * err_op - Print error if file dosen't open.
 * @op: pointer.
 * @file: name file.
 * Return: Nothing.
 */
void err_op(FILE *op, char *file)
{
	if (!op)
	{	fprintf(stderr, "Error: Can't open file %s", file);
		exit(EXIT_FAILURE);
	}
}
