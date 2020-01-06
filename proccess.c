#include "monty.h"
/**
 * _open - open file.
 * Return: Nothing.
 */
void _open(char *filename)
{
	global.file = fopen(filename, "r");
	err_op(filename);
}
/**
 * _read - read the file
 * Return: status.
 */
int _read(void)
{
	size_t len = 0;
	ssize_t status = 0;

	status = getline(&(global.buff), &len, global.file);
	return (status);
}
/**
 * _execute - execute opcode.
 * @status: status of getline in _read()
 * Return: Nothing.
 */
void _execute(void)
{
	char *inst = NULL;
	unsigned int line_number = 0;
	void (*opcd)(stack_t **stack, unsigned int line_number) = NULL;

	while (_read() != EOF)
	{
		line_number++;
		inst = strtok(global.buff, "\t\n ");
		if (inst && inst[0] != '#')
		{
			opcd = get(inst, line_number);
			global.new_n = strtok(NULL, "\t\n ");
			opcd(&(global.stack), line_number);
		}
		free(global.buff);
	}
	free_close();
}
