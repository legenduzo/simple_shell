#include "shell.h"

/**
 * cmd_manage - handle user input and execute commands
 * @buffer: input from user
 * @envp: envirement pointer
 * Return: 0 on sucess, 1 on failure, -1 to terminate terminal
 */

int cmd_manage(char *buffer, char **envp)
{
	pid_t pid;
	int status, i = 0;
	char *file_path;
	char **argv;

	argv = split_string(buffer);
	file_path = argv[0];

	pid = fork();

	if (pid == 0)
	{
		execve(file_path, argv, envp);
		perror("command not found");
		exit(1);
	}
	else if (pid > 0)
		wait(&status);

	else
	{
		perror("error");
		return (-1);
	}

	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}

	return (0);
}
