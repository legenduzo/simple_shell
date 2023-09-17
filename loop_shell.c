#include "shell.h"

/**
*shell_loop - loop that let the shell continue runing
*@envp: envirement pointer
*
*/

void shell_loop(char *envp[])
{
	char buffer[BUFFER_SIZE];
	char *read_line;

	while (1)
	{
		prompt();

		read_line = fgets(buffer, BUFFER_SIZE, stdin);
		if (!read_line
				|| !_strncmp(buffer, "exit", 4) || spacescheck(buffer) == _strlen(buffer))
		{
			if (read_line == NULL)
				write(1, "\n", 1);
			exit(0);
		}
		if (!_strncmp(buffer, "env", 3))
		{
			_envvar();
			continue;
		}
		if (cmd_manage(buffer, envp) == -1)
			continue;
	}
}
