#include "shell.h"

/**
*shell_loop - loop that let the shell continue runing
*
*
*/

void shell_loop(void)
{
	char buffer[BUFFER_SIZE];
	char *line = NULL;

	while (1)
	{
		if (!fgets(buffer, BUFFER_SIZE, stdin)
				|| !_strncmp(buffer, "exit", 4) || spacescheck(buffer) == _strlen(buffer))
		{
			exit(0);
		}
		if (!strncmp(buffer, "env", 3))
		{
			_envvar();
			continue;
		}
		cmd_manage(buffer);
	}
}
