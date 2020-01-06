#include "monty.h"
/**
 * proccess - proccess of program.
 * @av: argument values.
 * Return: Nothing.
 */
void proccess(char **av)
{
	char *filename = av[1];
	int status = 0;

	_open(filename);
	_execute(_read());
}
/**
 * _open - open file.
 * Return: Nothing.
 */
void _open(char *filename)
{
	global->file = fopen(filename, "r");
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

	status = getline(&(global->buff), &len, global->file);
	return (status);
}
/**
 * _execute - execute opcode.
 * @status: status of getline in _read()
 * Return: Nothing.
 */
void _execute(int status)
{
	char *inst = NULL;
	unsigned int line_number = 0;
	void (*opcd)(stack_t **stack, unsigned int line_number) = NULL;

	while (status != EOF)
	{
		line_number++;
		inst = strtok(global->buff, "\t\n ");
		if (inst && inst[0] != '#')
		{
			opcd = get(inst, line_number);
			global->new_n = strtok(NULL, "\t\n ");
			opcd(&(global->stack), line_number);
		}
	}
	free_close();
}
