#include "shell.h"

/**
 * read_line - prompt user and reads the input from stream
 *
 * Return: return line red from input stream
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
		free(buffer);
		exit(EXIT_FAILURE);
		/* Check for EOF (Ctrl+D) */
		/*
		if (feof(stdin))
		{
			printf("\n");
		}
		*/
	}
	/* check for new line character from input */
	line = malloc(sizeof(char) * n);
	/* note that strtok can also be used here */
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}

	/* free malloc'd variables */
	free(buffer);
	return (line);
}
