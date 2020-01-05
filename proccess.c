#include "monty.h"
/**
 * proccess - proccess of program.
 * @av: argument values.
 * Return: Nothing.
 */
void proccess(char **av)
{
	FILE *file;
	char *filename;

	filename = *av[1];
	file = _open(filename);
	_read(file);
	fclose(file);
	free(file);
}
FILE *_open(char *filename)
{
	FILE *file;

	file = fopen(filename, "r");
	err_op(file, filename);
	return file;
}
void _read(FILE *file)
{
	char *fLine = NULL;
	size_t len = 0;
	ssize_t status = 0;

	status = getline(&fLine, &len, file);
	_execute(status, fLine);
}
void _execute(int status, char *fLine)
{
	char inst[2048];
	stack_t *stack = NULL; 
	unsigned int line_number = 0;

	while (status != -1)
	{
		fLine = strtok(fLine, "\t\n ");
		strcpy(inst, fLine);
		line_number++;

	}
	free_stack(stack);
}
