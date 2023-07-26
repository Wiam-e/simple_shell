#include "shell.h"
/**
 * manage_exit - Handles the exit command in the shell program.
 * @usertok: Tokenized user input.
 * Return: Nothing.
 */
void manage_exit(char **usertok)
{
    char *l;
    int status = 0;

    if (usertok[1] == NULL || (!_strcmp(usertok[1], "0")))
    {
        free_token(usertok);
        free(l);
        exit(0);
    }

    status = _atoi(usertok[1]);
    if (status != 0)
    {
        free_token(usertok);
        free(l);
        exit(status);
    }
    else
    {
        _puts("EXIT: Illegal number: ");
        _puts(usertok[1]);
        _puts("\n");
        exit(2);
    }

    free_token(usertok);
    free(l);
    exit(EXIT_SUCCESS);
}
/**
 * manage_help - Opens the Shell help
 * Return: Nothing
 */
void manage_help(void)
{
	_puts("\n   HELP PAGE   \n");
}
