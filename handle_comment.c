#include "shell.h"
/**
*handle_comment - cuts a string when #
* @s: string to cut
 * Return: new string
 */
char *handle_comment(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
	if (s[i] == '#')
	{
		s[i] = '\0';
		break;
	}
	i++;
	}
	return (s);
}
