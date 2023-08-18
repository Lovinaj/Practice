#include <stdio.h>

size_t _strlen(const char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;

	return (len);
}
