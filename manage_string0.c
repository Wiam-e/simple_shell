#include "shell.h"
/**
* _strcpy - copies a string
* @dest: destination string
* @src: source string
* Return: pointer to destination
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
* _strncpy - copies a string
* @dest: destination string
* @src: source string
* @n: number of bytes to copy
* Return: pointer to the resulting string
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
{
	dest[i] = src[i];
	i++;
}
	while (i < n)
{
	dest[i] = '\0';
	i++;
}
return (dest);
}


/**
 * *_strdbl - copies the string given as parameter
* @str: string to duplicate
* Return: pointer to the copied string (Success),
*NULL if failed or if str is NULL
 */
char *_strdbl(char *str)
{
char *dbl;
unsigned int i = 0, l = 0;

if (str == NULL)
return (NULL);

while (str[l])
l++;
dbl = malloc(sizeof(char) * (l + 1));

if (dbl == NULL)
return (NULL);

while ((dbl[i] = str[i]) != '\0')
i++;

return (dbl);
}

/**
* *_strchr - locates a character in a string
* @s: string to search
* @c: char to find
* Return: a pointer to the first occurrence of the character
* c in the string s, or NULL if the character is not found
*/
char *_strchr(char *s, char c)
{
int a;

	while (1)
	{
	a = *s++;
	if (a == c)
	{
		return (s - 1);
	}
	if (a == 0)
	{
		return (NULL);
	}
	}
}
