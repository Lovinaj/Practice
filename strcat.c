#include <stdio.h>
#include <stdlib.h>

#include "shell.h"

char *_strcat(char *str1, char *str2)
{
	size_t len1 = _strlen(str1);
	size_t len2 = _strlen(str2);
	char *concat;

	concat = malloc((len1 + len2) * sizeof(char));
	if (!concat)
		return (NULL);
	_strcpy(concat, str1);
	_strcpy(concat + len1, str2);

	return (concat);
}
