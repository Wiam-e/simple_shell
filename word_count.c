#include "shell.h"
/**
  * count_word - Counts the words typed by the user
  * @str: The string that contains the words
  * Return: The number of words found in the string
  */
int count_word(char *str)
{
	int i = 0, cw = 0, state = 0;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			cw++;
		}

		i++;
	}

	return (cw);
}

/**
  * delimiter - Counts delimiters in a string
  * @str: The string that contains the delimiters
  * @deli: The delimiters to will find in the string
  * Return: The number of delimiters in the string
  */
int delimiter(char *str, char *deli)
{
	int i = 0, j = 0, cw = 0;

	while (deli[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == deli[i])
				cw++;
			j++;
		}
		i++;
	}
	return (cw);
}

/**
* _isalpha - function that checks the alphabet.
 * @c: The character to input
 * Return: 1 (Success), otherwise 0.
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
