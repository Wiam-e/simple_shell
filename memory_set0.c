#include "shell.h"
/**
 * set_to0 - sets all the bytes of an integer array to 0
 * @arr: Array to be initialized.
 * @size: Size of the array.
 * Return: Nothing
 */
void set_to0(unsigned int *arr, size_t size)
{
	size_t n;

	for (n = 0; n < size; n++)
		arr[n] = 0;
}

/**
 * set_null - sets all the characters in a char array to nulls
 * @arr: Array to be initialized.
 * @size: Size of the array.
 * Return: Nothing
 */
void set_null(char *arr, size_t size)
{
	size_t n;

	for (n = 0; n < size; n++)
		arr[n] = '\0';
}
