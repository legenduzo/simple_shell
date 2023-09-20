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
	char **argv;

	argv = split_string(buffer, ' ');
	if (!dirr(argv[0]))
		argv[0] = where(argv[0]);

	if (!argv[0])
	{
		perror("hsh");
		exit(1);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, envp);
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
	return (0); }
