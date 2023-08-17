#include "shell.h"

#include "shell.h"

/**
 * main - Entry point
 *
 * @argc: the argument counter
 * @argv: pointer to the commad line arguments entered
 * @env: the environment variable
 *
 * Return: always return 0
*/

int prompt(int argc, char *argv[], char **env)
{
	char *line;
	char **receivedArgs;

	
	receivedArgs = malloc(sizeof(char) * 1024);

	/* loop through to always display the dollar($) prompt */
	while (argc)
	{
		if (isatty(0) == 1)
			write(1, "$ ", 3);
		/* read line using function */
		line = getLine();
		receivedArgs = parse(line);

		/* when no argument is parsed, parse returns NULL */
		if (receivedArgs != NULL)
		{
			accessCommand(receivedArgs, argv, env);
		}
	}

	/* free malloc'd variables */
	free(line);
	free(receivedArgs);

	return (0);
}
