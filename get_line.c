#include "shell.h"

/**
 * getLine - prompt user and reads the input from stdin
 *
 * Return: return line red from input stdin
 */
char *getLine(void)
{
	char *line, *buffer = NULL;
	int i = 0, flag;
	size_t n;
	/* Read user input */
	flag = getline(&buffer, &n, stdin);
	if (flag == -1)
	{
		if (feof(stdin))
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
		free(buffer);
		exit(EXIT_FAILURE);
		}
	}
	/* check for new line character from input */
	line = malloc(sizeof(char) * n);

	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}

	/* free malloc'd variables */
	free(buffer);
	return (line);
}
