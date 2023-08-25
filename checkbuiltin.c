#include <ctype.h>
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
 * @argv: array of string containing command line arguments outside the shell
 * @env: An array of strings containing environment variables.
 * Return: void.
 */
void execute_builtin_command(char *command, char **args, char **argv,
	char *env[])
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
		shell_exit(command, args, argv);
	}
}

/**
 * shell_exit - function to exit the shell with status
 *
 * @command: The name of the built-in command.
 * @args: An array of arguments associated with the command.
 * @argv: array of string containing command line arguments outside the shell
 * Return: always return 0
*/

int shell_exit(char *command, char **args, char **argv)
{
	if (args[1] == NULL)
	{
		free(command);
		free(args);
		exit(0);
	}

	else if (isnumber(args[1]) == 0)
	{
		free(command);
		free(args);
		exit(atoi(args[1]));
	}
	else
	{
		write(2, argv[0], _strlen(argv[0]));
		write(2, ": 1: ", 5);
		write(2, "exit: ", 7);
		write(2, "Illegal number: ", 17);
		write(2, args[1], _strlen(args[1]));
		write(2, "\n", 1);
	}
	return (0);
}

/**
 * isnumber - checks if a string contains only integers
 *
 * @s: the string to check
 *
 * Return: return 0 if string contains only integers
 *	   return 1 otherwise
*/

int isnumber(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
