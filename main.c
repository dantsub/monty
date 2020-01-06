#include "monty.h"
monty_t global = {NULL, NULL, NULL, NULL};
/**
 * main - main the program.
 * @av:
 * @ac:
 * Return: 0 is success or 1 is fail.
 */
int main(int ac, char **av)
{
	char *filename = av[1];

	err_one_arg(ac);
	_open(filename);
	_execute(_read());
	exit(EXIT_SUCCESS);
}
