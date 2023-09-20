#include "shell.h"

/**
* _strncmp - compar two string till reach n
* @str1: parameter 1
* @str2: parameter 2
* @n: the function compare the string till it reaaches n
*
* Return: 1 on success, 0 on failure
*/

int _strncmp(const char *str1, const char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (0);
	}
	return (1);
}

/**
* _strlen - string length count
* @str: input string to count
* Return: number char's
*/

size_t _strlen(const char *str)
{
	int var = 0;

	if (!str)
		return (0);

	while (*str++)
		var++;
	return (var);
}

/**
**_strcpy - copy two strings
*@src: string 1
*@dest: string 2
*Return: a string with final result
*/

char *_strcpy(char *dest, const char *src)
{
	char *my_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (my_dest);
}

/**
**_strcat - concatenates two strings
*@src: string 1
*@dest: string 2
*Return: a string in which the two strings are appended
*/

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
