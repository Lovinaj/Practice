#include "shell.h"

/**
 * env_variable - reads envrionment varibles of the system and searches for the
 *		  PATH varialbe
 *
 * @env: array containing the environment variables
 *
 * Return: return the PATH environment variable if found
 *	   return NULL if PATH variable is empty or not found
*/

char **env_variable(char **env)
{
	int i;
	char **path = NULL;

	if (env == NULL)
		return (NULL);

	for (i = 0; env[i] != NULL; i++)
	{
		path = parse(env[i], "=");
		if (_strcmp(path[0], "PATH") == 0)
			return (path);
		free(path);
	}
	return (NULL);
}
