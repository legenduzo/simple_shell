#include "shell.h"

/**
*main - Entry point to the shell
*Return: always 0 (success)
*/

int main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	shell_loop(envp);
	return (0);
}
