#include "shell.h"

/**
 * get_string - returns an array of a single string and null
 * @str: string to return
 * @i: number of char in the string
 * @start: index to start from
 *
 * Return: Array of strings on success, NULL on failure
 */

char *get_string(char *str, int i, char delim, int start)
{
	int n;
	char *word;

	while (str[start] == delim)
		start += 1;

	n = i - start;
	word = malloc(n + 1);
	if (!word)
		return (NULL);

	strncpy(word, &str[start], n);
	word[n] = '\0';

	return (word);
}

/**
 * strings - returns a null terminated array of strings
 * @str: string to split up
 * @words: pointer to strings
 *
 * Return: Array of strings or NULL;
 */

char **strings(char *str, char delim, char **words)
{
	int j = 0, i = 0;
	int start = 0;
	int n;

	if (str[i] == delim)
		i++;

	while (str[i] != '\0')
	{
		if (str[i] == delim && str[i - 1] != delim)
		{
			while (str[start] == delim)
				start += 1;

			n = i - start;
			words[j] = malloc(n + 1);
			if (!words[j])
				return (NULL);

			strncpy(words[j], &str[start], n);
			words[j][n] = '\0';
			j++;
			start = i;
		}
		i++;
	}
	if (str[i] == '\0' && str[i - 1] != delim)
	{
		while (str[start] == delim)
			start += 1;

		n = i - start;
		words[j] = malloc(n + 1);
		if (!words[j])
			return (NULL);

		strncpy(words[j], &str[start], n);
		words[j][n] = '\0';
		words[j + 1] = NULL;

		return (words);
	}
	else
	{
		words[j] = NULL;

		return (words);
	}
}

/**
 * split_string - splits a string at the delimiter.
 * @str: string to split
 * @delim: the delimeter to use for splitting
 *
 * Return: Array of strings on success, NULL on failure
 */

char **split_string(char *str, char delim)
{
	int i, word_count = 0;
	char **words;

	if (!str || !delim)
		return (NULL);

	if (check_char(str) == 0)
		return (NULL);

	for (i = 0; (size_t) i < _strlen(str); i++)
	{
		if (str[i] == '\n')
			str[i] = ' ';
	}
	i = 0;

	if (str[i] == delim)
		i++;

	while (str[i] != '\0')
	{
		if (str[i] == delim && str[i - 1] != delim)
			word_count++;
		i++;
	}

	if (str[i] == '\0' && str[i - 1] == delim)
		words = malloc((word_count + 1) * sizeof(char *));
	else
		words = malloc((word_count + 2) * sizeof(char *));

	if (!words)
		return (NULL);

	return (strings(str, delim, words));
}
