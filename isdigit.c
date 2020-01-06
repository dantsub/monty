#include "monty.h"
/**
 * _isdigit - verify is a number.
 * Return: 0 if not a number or 1 is a number.
 */
int _isdigit(void)
{
        int idx = 0;

        while (global->new_n[idx] != '\0')
        {
                if (!isdigit(global->new_n[idx]) && global->new_n != '-')
                        return (0);
                idx++;
        }
        return (1);
}
