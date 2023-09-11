#ifndef SHELL_H
#define SHELL_H
#define BUFFER_SIZE 1024
extern char **environ;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>


void _envvar(void);
void rm_bin(char *str);
size_t spchk(char *str);
char *isdir(char *str);
int dirr(char *str);
void remove_space_and_newline(char *str);

#endif
