<<<<<<< HEAD
#include "shell.h"

/**
 * _isdigit - checks for digit
 * @c: parameter to be checked
 * Return: 1 for digit and 0 for other
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
=======
/**
 * _isdigit - checks if input is digit between 0 - 9
 *
 * @c: input
 *
 * Return: 1 if is digit, 0 if not
*/

int _isdigit(int c)

{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
>>>>>>> 4514e84 (exit status)
}
