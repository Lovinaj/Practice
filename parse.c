#include "shell.h"

/**
 * parse - parses the line read into command line arguments
 *
 * @line: the line to tokenize
 *
 * Return: return a list of all strings passed from the command line
 */
char **parse(char *line)
{
	char *token;
	char **arrayStr;
	int i, buffsize = BUFFSIZE_STD;

	arrayStr = malloc(sizeof(char *) * buffsize);
	if (arrayStr == NULL)
	{
		perror("Memory allocation for list of tokens");
		exit(EXIT_FAILURE);
	}
	/* Tokenize the input line using the specified delimiter */
	token = strtok(line, DELIM);

	if (token == NULL)
		return (NULL);
	/* Loop to tokenize the entire input line */
	for (i = 0; token != NULL; i++)
	{
		arrayStr[i] = token;

		if (i >= buffsize)
		{
			buffsize += BUFFSIZE_STD;
			/* Reallocate memory for the arrayStr array with the new buffer size */
			arrayStr = realloc(arrayStr, buffsize * sizeof(char *));
			if (arrayStr == NULL)
			{
				perror("Memory reallocation fails");
				exit(EXIT_FAILURE);
			}
		}
		/* Get the next token */
		token = strtok(NULL, " ");
	}
	/* Null-terminate the array of char pointers */
	arrayStr[i] = NULL;
	return (arrayStr);
}

