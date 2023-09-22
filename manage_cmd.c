#include "shell.h"

/**
 *print_error - to print an error and exit the program
 *@exit_code: the exit code
 *@argument: arg
 */

void print_error(int exit_code, char *argument)
{
	perror(argument);
	exit(exit_code);
}

/**
 * **helper_func - make sure we have the good argv
 * @argv: argument vector coming from main function
 * Return: it will return the argv that we have checked
 */

char **helper_func(char **argv)
{
	char *temp;
	if (!argv)
		print_error(1, "hsh");

	if (!dirr(argv[0]))
	{
		temp = malloc(strlen(argv[0]) + 1);
		strcpy(temp, argv[0]);
		free(argv[0]);
		argv[0] = NULL;
		argv[0] = where(temp);
		free(temp);
	}

	return (argv);
}

/**
 * cmd_manage - handle user input and execute commands
 * @buffer: input from user
 * @envp: envirement pointer
 * Return: 0 on sucess, 1 on failure, -1 to terminate terminal
 */

int cmd_manage(char *buffer, char **envp)
{
	pid_t pid;
	int status;
	char **argv;
	char *cmd;

	argv = split_string(buffer, ' ');
	cmd = argv[0];
	argv = helper_func(argv);

	if (!argv[0])
	{
		fprintf(stderr, "hsh: 1: %s: not found\n", cmd);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, envp);
		print_error(2, argv[0]);
	}
	else if (pid > 0)
		wait(&status);
	else
		print_error(-1, argv[0]);

	free_split(argv);

	return (0);
}
