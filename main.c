#include "shell.h"

/**
*main - Entry point to the shell
*@argc: argument count in the argv
*@argv: array of pointers to the arguments
*@envp: envirement pointer
*Return: always 0 (success)
*/

int main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	shell_loop(envp);
	return (0);
}
