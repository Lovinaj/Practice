#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

#define MAX_INPUT_LENGTH 1024
#define BUFFSIZE_STD 128
#define DELIM " " 

int prompt(int argc, char **argv, char **env);
char *getLine(void);
char **parse(char *line);
void create_process(char **arrayStr, char **argv, char *env[]);
void accessCommand(char **arrayStr, char **argv, char *env[]);

#endif
