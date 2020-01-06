#include "monty.h"
/**
 * get - get the function according to the argument s.
 * @s: string.
 * @l: line_number.
 * Return: nothing.
 */
void (*get(char *s, unsigned int l))(stack_t **stack, unsigned int line_number)
{
	int idx;

	instruction_t op[] = {
			{"stack", queue_stack},
			{"queue", queue_stack},
			{"pchar", _pchar},
			{"pstr", _pstr},
			{"push", _push},
			{"pall", _pall},
			{"pint", _pint},
			{"swap", _swap},
			{"pop", _pop},
			{"nop", _nop},
			{"add", _add},
			{"sub", _sub},
			{"mul", _mul},
			{"div", _div},
			{"mod", _mod},
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
