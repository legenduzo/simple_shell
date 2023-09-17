#include "shell.h"

/**
*cmd_manage - handle user inpute and execute commands
*@buffer: input from user
*@envp: envirement pointer
*Return: 0 on sucess or -1 on fail
*/

int cmd_manage(char *buffer, char *envp[])
{
	pid_t pid;
	int status = 0;
	char *file_path, *args = NULL, *args2 = NULL;
	char **argv;

	if (_strncmp(buffer, "/bin/", 5) == 0)
		rm_bin(buffer);

	_strcpy(file_path, "/bin/");
	/**still working on tokinizerr function to split*/
	/**the user input it should be on var file_path*/
	pid = fork();
	remove_space_and_newline(buffer);

	if (pid < 0)
		return (-1);

	if (!pid)
	{
		if (!args && !args2)
		{
			argv[0] = buffer;
			argv[1] = NULL;
			strcat(file_path, buffer);

			if (execve(file_path, argv, envp) == -1)
			{
				perror("command not found");
				exit(0);
			}
		}
		else if (dirr(args2) == 0)
		{
			argv[0] = file_path;
			argv[1] = args;
			argv[2] = args2;
			argv[3] = NULL;

			if (execve(file_path, argv, NULL) == -1)
			{
				perror("cmd not found or wrong path");
				exit(0);
			}
		else if (args && (dirr(args) == -1))
		{
			argv[0] = file_path;
			argv[1] = args;
			argv[2] = NULL;

			if (execve(file_path, argv, NULL) == -1)
			{
				perror("command not found");
				exit(0);
			}
		}
	}
	else
		waitpid(pid, &status,  0);

	return (0);
}
