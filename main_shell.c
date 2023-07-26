#include "shell.h"
/**
  * main - Entry point to Shell
  * Return: 0.
  */
int main(void)
{
	char *line = NULL, **usertok = NULL;
	int word_len = 0, execFlag = 0;
	size_t line_size = 0;
	ssize_t line_len = 0;

	while (line_len >= 0)
	{
		signal(SIGINT, manage_sig);
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);

		line_len = getline(&line, &line_size, stdin);
		if (line_len == -1)
		{
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
		break;
		}

		word_len = count_word(line);
		if (line[0] != '\n' && word_len > 0)
		{
		usertok = str_tok(line, " \t", word_len);
		execFlag = execute_builtin(usertok, line);
		if (!execFlag)
			{
		usertok[0] = check_cmd(usertok[0]);
		if (usertok[0] && access(usertok[0], X_OK) == 0)
		_execute(usertok[0], usertok);
		else
		perror("./hsh");
			}
		free_token(usertok);
		}
	}

	free(line);
	return (0);
}
