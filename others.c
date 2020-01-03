#include "monty.h"
/**
 * free_stack - free a stack.
 * @stack: stack.
 * Return: nothing.
 */
void free_stack(stack_t *stack)
{
    if (stack)
    {   free_stack(stack->next);
        free(stack);
    }
}
