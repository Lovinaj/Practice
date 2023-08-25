#include "shell.h"

/**
 *  _strcat - Concatenates two strings.
 * @str1: This is the destination string.
 * @str2: This is the source string to be appended.
 * Return: A pointer to the concatenated string @str1
 */
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
