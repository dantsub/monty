#include "monty.h"
/**
 * main - main the program.
 * @av:
 * @ac:
 * Return: 0 is success or 1 is fail.
 */
int main(int ac, char **av)
{
	err_one_arg(ac);
	proccess(**av);
	return (EXIT_SUCCESS);
}
