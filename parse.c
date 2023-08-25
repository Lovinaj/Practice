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
	char *token = NULL;
	char **arrayStr = NULL;
	int i, buffsize = BUFFSIZE_STD;


	arrayStr = malloc(sizeof(char *) * buffsize);
	if (arrayStr == NULL)
	{
		perror("Memory allocation for list of tokens");
		free(arrayStr);
		exit(EXIT_FAILURE);
	}
	/* Tokenize the input line using the specified delimiter */
	token = strtok(line, DELIM);

	if (token == NULL)
		return (NULL);
	/* Loop to tokenize the entire input line */
	for (i = 0; token != NULL; i++)
	{
		if (i >= buffsize)
		{
			buffsize += BUFFSIZE_STD;
			/* Reallocate memory for the arrayStr array with the new buffer size */
			arrayStr = realloc(arrayStr, buffsize * sizeof(char *));
			if (arrayStr == NULL)
			{
				perror("Memory reallocation failed");
				free(arrayStr);
				exit(EXIT_FAILURE);
			}
		}
		/* Store the token in the array only if it's not NULL */
		arrayStr[i] = token;
		/* Get the next token */
		token = strtok(NULL, " ");
	}
	/* Null-terminate the array of char pointers */
	arrayStr[i] = NULL;
	free(token);
	return (arrayStr);
}
