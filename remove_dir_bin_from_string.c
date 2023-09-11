#include "shell.h"

/**
*rm_bin -  function that search for /bin/ and removes it from the given string
*@str: string
*/

void rm_bin(char *str)
{
	char *prx = "/bin/";
	size_t prx_len = _strlen(prx);

	if (_strncmp(str, prx, prx_len) == 0)
	{
		size_t new_length = strlen(str + prx_len);

		memmove(str, str + prx_len, new_length + 1);
	}
}
