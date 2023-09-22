#include "shell.h"

/**
 * free_split - frees split_string
 * @str: pointer to char * to free
 *
 * Return: void
 */

void free_split(char **str)
{
	int i = 0;

	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free(str);
		str = NULL;
	}
}
