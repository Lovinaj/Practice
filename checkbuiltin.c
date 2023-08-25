#include "shell.h"

/**
 * is_builtin_command - Check if a command is a built-in command.
 * @command: The command to check.
 * Return: 1 if command is a built-in, 0 otherwise.
 */

int is_builtin_command(char *command)
{
	char *builtins[] = {"cd", "exit", "env"};
	size_t i;

	for (i = 0; i < sizeof(builtins) / sizeof(builtins[0]); i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}


/**
 * execute_builtin_command - Execute built-in commands.
 * @command: The name of the built-in command.
 * @args: An array of arguments associated with the command.
 * @env: An array of strings containing environment variables.
 * Return: void.
 */
void execute_builtin_command(char *command, char **args, char *env[])
{
	int i;

	if (_strcmp(command, "cd") == 0)
	{
		if (args[1] != NULL)
		{
			if (chdir(args[1]) != 0)
			{
				perror("cd");
			}
		}
	} else if (_strcmp(command, "env") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			printf("%s\n", env[i]);
		}
	} else if (_strcmp(command, "exit") == 0)
	{
		free(args);
		free(command);
		exit(0);
	}
}
