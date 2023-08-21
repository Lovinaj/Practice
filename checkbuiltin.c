#include "shell.h"

/**
 * is_builtin_command - Check if a command is a built-in command.
 * @command: The command to check.
 * Return: 1 if command is a built-in, 0 otherwise.
 */

int is_builtin_command(const char *command) 
{
    char *builtins[] = {"cd", "exit"};
    size_t i;

    for (i = 0; i < sizeof(builtins) / sizeof(builtins[0]); i++) {
        if (strcmp(command, builtins[i]) == 0) {
            return (1);
        }
    }
    return 0;
}


/**
 * execute_builtin_command - Execute built-in commands.
 * @command: The name of the built-in command.
 * @args: An array of arguments associated with the command.
 * Return: None.
 */
void execute_builtin_command(const char *command, char **args) {
    if (strcmp(command, "cd") == 0) {
        
        if (args[1] != NULL) {
            if (chdir(args[1]) != 0) {
                perror("cd");
            }
        }
    } else if (strcmp(command, "exit") == 0) {
        
        exit(0);
    }
}
