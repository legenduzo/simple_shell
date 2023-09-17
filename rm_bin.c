#include "shell.h"

/**
*rm_bin -  function that search for /bin/ and removes it from the given string
*@str: string
*/

void rm_bin(char *str)
{
	char *bin = "/bin/";
	int bin_len = 5;
	int new_length;

	if (strncmp(str, bin, bin_len) == 0)
	{
		new_length = strlen(str) - bin_len;

		memmove(str, str + bin_len, new_length + 1);
	}
}
