#include "monty.h"
/**
 * free_stack - free a stack.
 * @stack: stack.
 * Return: nothing.
 */
void free_stack(stack_t *stack)
{
	if (stack)
	{	free_stack(stack->next);
		free(stack);
	}
}
/**
 * free_close - free all and close the file.
 * Return: Nothing.
 */
void free_close(void)
{
	if (global.file)
		fclose(global.file);
	if (global.buff)
		free(global.buff);
	if (global.stack)
		free_stack(global.stack);
}
