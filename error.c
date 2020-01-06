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
		free_close();
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
		fprintf(stderr, "L%u: usage: push integer\n", line);
		break;
	case 2:
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		break;
	case 3:
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		break;
	case 4:
		fprintf(stderr, "L%u: can't %s, stack too short\n", line, opcd);
		break;

	default:
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcd);
		break;
	}
	free_close();
	exit(EXIT_FAILURE);
}
/**
 * err_op - Print error if file dosen't open.
 * @file: name file.
 * Return: Nothing.
 */
void err_op(char *filename)
{
	if (!global.file)
	{	fprintf(stderr, "Error: Can't open file %s\n", filename);
		free_close();
		exit(EXIT_FAILURE);
	}
}
