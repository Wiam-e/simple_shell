#include "shell.h"
/**
  * get_envi - Retrieves the value of an environment's variable
  * @name: The name of the environment variable
  * Return: The value of the environment variable,
  * otherwise NULL.
  */
char *get_envi(const char *name)
{
	int i = 0;
	char *var = NULL;

	while (environ[i])
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			var = _strdbl(environ[i]);
			while (*var != '=')
				var++;

			++var;
			return (var);
		}
		i++;
	}

	return (NULL);
}

/**
  * print_env - Prints the environment built-in
  * Return: Nothing to returns
  */
void print_env(void)
{
	int i = 0, j = 0;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}

		if (j != 0)
			_putchar('\n');
		i++;
	}
}


/**
  * rm_new_line - Removes new line character from string
  * @str: The string
  * Return: The string without a new line character
  */
char *rm_new_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}

	return (str);
}
