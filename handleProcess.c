#include "shell.h"
/**
 * create_process - system execution with fork
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
		perror(argv[0]);
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

void accessCommand(char **arrayStr, char **argv, char *env[])
{
	char *command = _strcat("/bin/", arrayStr[0]);

	if (access(arrayStr[0], F_OK) == 0)
		create_process(arrayStr[0], arrayStr, argv, env);
	else if (access(command, F_OK) == 0)
		create_process(command, arrayStr, argv, env);
	else
		perror(argv[0]);
}
