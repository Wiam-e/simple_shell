#include "shell.h"
/**
 * _strconslen - counts the number of characters in a constant string
 * @str: constant string
 * Return: number of characters in the string
 */

int _strconslen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * print_error - prints an error message
 * @argv: name of the program
 * @count: number of commands entered
 * @cmd: command entered
 * @msg: error message
 */

void print_error(char *argv, int count, char *cmd, char *msg)
{
	char *count_str = NULL;

	write(STDERR_FILENO, argv, _strconslen(argv));
	write(STDERR_FILENO, ": ", 2);
	count_str = _itoa(count);
	write(STDERR_FILENO, count_str, _strconslen(count_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, _strconslen(msg));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strconslen(cmd));
	write(STDERR_FILENO, "\n", 1);
	free(count_str);
}
