#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - function that prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (str == NULL)
	return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
* manage_sig - manages the signal and blocks ctrl+c
* @signal_n: the signal number
* Return: void
*/
void manage_sig(__attribute__((unused))int signal_n)
{
if (signal_n == SIGINT)
write(STDOUT_FILENO, "\n($) ", 5);
}

/**
* _atoi - converts a string to an integer
* @s: string to be converted
* Return: the int converted from the string
*/
int _atoi(char *s)
{
	int min = 1, c = 0, p = 0;
	unsigned int ui = 0;

	while (s[p])
	{
		if (s[p] == '-')
			min *= -1;

		while (s[p] >= '0' && s[p] <= '9')
		{
			c = 1;
			ui = (ui * 10) + (s[p] - '0');
			p++;
		}
		if (c == 1)
			break;

		p++;
	}
	ui *= min;
	return (ui);
}
