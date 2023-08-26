#include "shell.h"

/**
 * * _isdigit - checks for digit
 * * @c: parameter to be checked
 * * Return: 1 for digit and 0 for other
 * */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
	return (1);
	}
	return (0);
}
