#include "shell.h"
/**
 * create_process - system execution with fork
 * @arrayStr: Array of strings gotten from the command line
 * @argv: Argument vector
 * @env: Environment variable from parent
 * Return: void
*/

void create_process(char **arrayStr, char **argv, char *env[])
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
	if (execve(arrayStr[0], arrayStr, env) == -1)
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

	if (access(arrayStr[0], F_OK) == 0)
	{
		create_process(arrayStr, argv, env);
	}
	else
	{
		perror(argv[0]);
	}
}
