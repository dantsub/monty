#include "monty.h"
/**
 * _isdigit - verify is a number.
 * Return: 0 if not a number or 1 is a number.
 */
int _isdigit(void)
{
	int idx, cnt;

	idx = cnt = 0;
	while (global.new_n[idx] != '\0')
	{
		if (global.new_n[idx] == '-')
			cnt++;
		else 
		{
			if (global.new_n[idx] >= 'a' && global.new_n[idx] <= 'z')
				return (0);
			if (global.new_n[idx] >= 'A' && global.new_n[idx] <= 'Z')
				return (0);
		}
		idx++;
	}
	if (cnt > 1)
		return (0);
	return (1);
}
