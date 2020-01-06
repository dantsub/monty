#include "monty.h"
/**
 * get - get the function according to the argument s.
 * @s: string.
 * Return: nothing.
 */
void (*get(char *s, unsigned int l))(stack_t **stack, unsigned int line_number)
{
	int idx;

	instruction_t op[] = {
			{"push", _push},
			{"pall", _pall},
			{"pint", _pint},
			{"swap", _swap},
			{"pop", _pop},
			{"add", _add},
			{NULL, NULL}
	};

	for (idx = 0; op[idx].opcode != NULL; idx++)
	{
		if (!(strcmp(s, op[idx].opcode)))
			return (op[idx].f);
	}
	err_line(l, s, 0);
	exit(EXIT_FAILURE);
}
