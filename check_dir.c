#include "shell.h"

/**
*dirr - check if the given string is a dir
*@str: string
*Return: 0 if found a dir in the string or -1 if not found
*/

int dirr(char *str)
{
	int i = 0, t = 0;
	char dir[] = "/";

	while (*str)
	{
		if (str[i] == dir[0] || (str[0] == '.' && str[1] == '/'))
		{
			t++;
		}
		i++;
		str++;
	}
	if (t > 0)
	{
		return (0);
	}
	return (-1);
}
