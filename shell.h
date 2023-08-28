#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 1024
#define BUFFSIZE_STD 128
#define DELIM " \t\r\a\n"

int prompt(int argc, char **argv, char **env);
char *getLine(char *buffer, int status);
char **parse(char *line);
void create_process(char *command, char **arrayStr, char **argv, char *env[]);
int accessCommand(char **arrayStr, char **argv, char *env[]);
char *_strcat(char *str1, char *str2);
size_t _strlen(const char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int is_builtin_command(char *command);
void execute_builtin_command(char *command, char **args, char **argv,
	char *env[]);
int shell_exit(char *command, char **args, char **argv);
int isnumber(char *s);

#endif
