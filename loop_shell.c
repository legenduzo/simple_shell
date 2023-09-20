#include "shell.h"

/**
*shell_loop - loop that let the shell continue runing
*@envp: envirement pointer
*
*/

void shell_loop(char **envp)
{
	char buffer[BUFFER_SIZE];
	char *read_line;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			write(1, "$ ", _strlen("$ "));

		read_line = fgets(buffer, BUFFER_SIZE, stdin);

		if (!read_line || _strncmp(buffer, "exit", 4))
		{
			if (is_interactive && read_line == NULL)
				write(1, "\n", 1);
			exit(0);
		}

		if (spacescheck(buffer) == _strlen(buffer))
			continue;

		if (_strncmp(buffer, "env", 3))
		{
			_envvar(envp);
			continue;
		}
		if (cmd_manage(buffer, envp) == -1)
			continue;
	}
}
