#include "shell.h"
/**
 * create_process - system execution with fork
 * @command: The command to be executed
 * @arrayStr: Array of strings gotten from the command line
 * @argv: Argument vector
 * @env: Environment variable from parent
 * Return: void
*/

void create_process(char *command, char **arrayStr, char **argv, char *env[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(argv[0]);
		return;
	}
	if (child_pid == 0)
	{
		if (execve(command, arrayStr, env) == -1)
		{
			free(command);
			free(arrayStr);
			perror(argv[0]);
		}
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * accessCommand - Accesses and executes a command.
 * @arrayStr: An array of strings representing the command and its arguments.
 * @argv: An array of strings containing command-line arguments.
 * @env: An array of strings containing environment variables.
 * Return: None.
 */
void accessCommand(char **arrayStr, char **argv, char *env[])
{
	char *command = _strcat("/bin/", arrayStr[0]);

	if (is_builtin_command(arrayStr[0]))
	{
		free(command);
		execute_builtin_command(arrayStr[0], arrayStr, env);
	}
	else if (access(arrayStr[0], F_OK) == 0)
	{
		free(command);
		create_process(arrayStr[0], arrayStr, argv, env);
	}
	else if (access(command, F_OK) == 0)
		create_process(command, arrayStr, argv, env);
	else
	{
		write(2, argv[0], _strlen(argv[0]));
		write(2, ": ", 2);
		write(2, "1: ", 3);
		write(2, arrayStr[0], _strlen(arrayStr[0]));
		write(2, ": not found\n", 12);
		free(command);
	}

}
