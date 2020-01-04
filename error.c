#include "monty.h"
/**
 * 
 * 
 * 
 */
void err_one_arg(int ac, char **av)
{
    if (ac < 2)
    {
        printf("USAGE: monty file");
        exit(EXIT_FAILURE);
    }
}
