#include "shell.h"
/**
  * str_tok - Extract tokens from string
  * @str: The string to tokenize
  * @deli: The delimiter of tokenization
  * @n: Tokens number
  * Return: An array of tokens of the string
  */
char **str_tok(char *str, char *deli, int n)
{
	char **tok = NULL, *tk = NULL, *temp = NULL;
	int i = 0;

	tok = malloc(sizeof(char *) * (n + 1));
	if (!tok)
		return (NULL);

	str = rm_new_line(str);
	temp = _strdbl(str);
	tk = strtok(temp, deli);

	while (tk)
	{
		tok[i] = _strdbl(tk);
		tk = strtok(NULL, deli);
		i++;
	}

	tok[i] = NULL;
	free(temp);
	return (tok);
}
