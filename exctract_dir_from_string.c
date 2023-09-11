#include "shell.h"

/**
*isdir - check if dir exist in the string and exctracte it
*@str: string
*Return: exctracted dir from the string
*/

char *isdir(char *str)
{
	int i = 0, p = 0;
	char *str2 = "/";

	while (str[i])
	{
		if (str[i] == str2[p])
		{
			while (str[p])
			{
				str[p] = str[i];
				p++;
				i++;
			}
		}
		i++;
	}
	return (str); }
