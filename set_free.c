#include "shell.h"
/**
  * frees_get_env - frees the environment
  * @var: The environment variable to free
  * Return: Nothing
  */
void frees_get_env(char *var)
{
	int i;

	for (i = 4; i >= 0; i--)
		var--;

	free(var);
}

/**
  * free_token - frees tokens
  * @tok: parametre
  * Return: Nothing
  */
void free_token(char **tok)
{
	char **temp = tok;

	if (tok)
	{
		while (*tok)
			free(*tok++);

		free(temp);
	}
}

/**
* freep - frees a pointer and NULLs the address
 * @ptr: pointer to free
 * Return: 1 (Success), otherwise 0.
 */
int freep(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
