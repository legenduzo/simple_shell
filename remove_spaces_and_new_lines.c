#include "shell.h"

/**
*remove_space_and_newline - function to remove space or new line from a sting
*@str: string
*/

void remove_space_and_newline(char *str)
{
	int j = 0;
	size_t i = 0;

	for ( ; i < _strlen(str); i++)
	{
		if (str[i] != ' ' && str[i] != '\n')
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}
