#include "shell.h"

/**
*spchk - count spaces in a string
*@str: string
*Return: 0 for not space or non-zero for space
*/

size_t spaceschk(char *str)
{
	int i = 0, sp = 0;

	while (str[i])
	{
		if (isspace(str[i]))
		{
			sp++;
		}
		i++;
	}
	return (sp);
}
