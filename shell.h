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
size_t spacescheck(char *str);
char *isdir(char *str);
int dirr(char *str);
void remove_space_and_newline(char *str);
int check_char(char *str);
char **split_string(char *str);
int _strncmp(const char *str1, const char *str2, int n);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
void shell_loop(char *envp[]);
int cmd_manage(char *buffer, char *envp[]);
void prompt(void);

#endif
