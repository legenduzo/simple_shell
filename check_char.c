#include "shell.h"

/**
 * check_char - checks to see if a string contains a - z
 * @str: string to check
 *
 * Return: number of characters. 0 if there are no characters
 */

int check_char(char *str)
{
	int i, n = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] + 0 >= 'a' && str[i] + 0 <= 'z')
			n++
	}
	return (n);
}
