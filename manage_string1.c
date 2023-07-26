#include "shell.h"
/**
* _strlen - returns the length of a string
* @s: string to evaluate
*
* Return: the length of the string
*/
int _strlen(const char *s)
{
int i = 0;

while (s[i] != '\0')
{
i++;
}
return (i);
}
/**
* _strcmp - compares two strings
* @s1: first string to compare
* @s2: second string to compare
* Return: negative if s1 is less than s2, 0 if they're equal,
* more than 0 if s1 is greater than s2
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 == *s2)
{
if (*s1 == '\0')
{
return (0);
}
s1++;
s2++;
}
return (*s1 - *s2);
}


/**
 * hays_check - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
* Return: address of next char of haystack or NULL
 */
char *hays_check(const char *haystack, const char *needle)
{
	while (*needle)
	{
	if (*needle++ != *haystack++)
	return (NULL);
	}
	return ((char *)haystack);
}

/**
* _strcat - concatenates two strings
* @dest: string to append to
* @src: string to add
* Return: a pointer to the resulting string
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
	dest[i] = src[j];
	j++;
	i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
  * _strncmp - Compares at most the first n bytes of str1 and str2
  * @s1: The first string
  * @s2: The second string
  * @l: The limit bytes of comparison
  * Return: int value
  */
int _strncmp(const char *s1, const char *s2, size_t l)
{
	unsigned int p = 0;
	int diff = 0;

	while (p < l)
	{
		if (s1[p] == s2[p])
		{
			p++;
			continue;
		}
		else
		{
			diff = s1[p] - s2[p];
			break;
		}

		p++;
	}
	return (diff);
}
