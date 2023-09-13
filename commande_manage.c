#include "shell.h"

/**
*cmd_manage - handle and execute commandes
*
*/

void cmd_manage(char *buffer)
{
	int sp = 0;
	char file_path[100];
	char *args = NULL, *args2 = NULL, *new_file_path = NULL, *argv[100];

	if (_strncmp(buffer, "/bin/", 5) == 0)
	{
		rm_bin(buffer);
	}
	_strcpy(file_path, "/bin/");
	
	/**tokinize function*/

	pid = fork();
	rmvSNl(buffer);
                if (pid < 0)
                { continue; }
                if (!pid)
                {
                        if (!args && !args2)
                        { argv[0] = buffer, argv[1] = NULL, strcat(file_path, buffer);
                                if (execve(file_path, argv, NULL) == -1)
                                        perror("command not found"), exit(0); }
                        else if (dirr(args2) == 0)
                                        { argv[0] = file_path, argv[1] = args, argv[2] = args2, argv[3] = NULL;
                                if (execve(file_path, argv, NULL) == -1)
                                        perror("cmd not found or wrong path"), exit(0); }
                        else if (args && dirr(args) == -1)
                                        { argv[0] = file_path, argv[1] = args, argv[2] = NULL;
                                if (execve(file_path, argv, NULL) == -1)
                                        perror("command not found"), exit(0); } } else
                { waitpid(pid, &status, 0), free(args); } }
        return (0);
}
