#include "shell.h"

/**
 * getLine - prompt user and reads the input from stdin
 *
 * Return: return line red from input stdin
 */
char *getLine(char *buffer)
{
	int flag;
	size_t n;
	/* Read user input */

	flag = getline(&buffer, &n, stdin);
	if (flag == -1)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	buffer[strlen(buffer) - 1] = '\0';
	return (buffer);
}
