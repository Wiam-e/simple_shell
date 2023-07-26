#include "shell.h"
/**
* _memset - Fills the first n bytes of memory pointed by s.
*with a constant byte b
* @s: buffer array
* @b: constant byte
* @n: number of bytes of memory to fill
* Return: Pointer to memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	while (n > 0)
	{
	s[i] = b;
	i++;
	n--;
	}
	return (s);
}

/**
 * free_mem - frees memory allocated to a 2 dimentional character array.
 * @mem: mem to be freed.
 * Return: Nothing.
 */
void free_mem(char **mem)
{
    int i = 0;

    while (mem[i] != NULL)
    {
        free(mem[i]);
        i++;
    }
    free(mem);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous memory allocated
 * @prv_size: byte size of former block
 * @new_size: byte size of new block
 *
 * Return: pointer of old block.
 */
void *_realloc(void *ptr, unsigned int prv_size, unsigned int new_size)
{
	char *p;

	if (ptr == NULL)
		return (malloc(new_size));

if (new_size == 0)
{
free(ptr);
return (free(ptr), NULL);
}
	if (new_size == prv_size)
		return (ptr);

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);

	prv_size = prv_size < new_size ? prv_size : new_size;
	while (prv_size--)
		p[prv_size] = ((char *)ptr)[prv_size];
	free(ptr);
	return (p);
}


/**
 * free_p - frees a pointer and NULLs the address
 * @ptr: pointer to free
 * Return: 1 (Success), otherwise 0.
 */
int free_p(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
