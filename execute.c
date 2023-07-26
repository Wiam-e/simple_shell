#include "shell.h"
/**
 * _execute - Executes a command
 * @cmd: The command to execute
 * @ops: The options or flags to the command
 * Return: status value
 */
int _execute(char *cmd, char **ops)
{
	pid_t child;
	int status;

	switch (child = fork())
	{
	case -1:
		perror("Error creating child process");
		exit(EXIT_FAILURE);
	case 0:
		execve(cmd, ops, environ);
		/* Add break statement */
		break;
	default:
		wait(&status);
		break;
	}
		return (0);
}

/**
 * execute_builtin - Executes a built-in command
 * @usertok: user tokens
 * @line: input line
 * Return: 1 if it is a built-in command, otherwise 0.
 */
int execute_builtin(char **usertok, char *line)
{
	int i = 0;
	char *builtcmd[] = {"exit", "cd", "help", "env", NULL};

	while (builtcmd[i])
	{
		if (_strcmp(usertok[0], builtcmd[i]) == 0)
		{
			switch (i)
			{
			case 0:
				manage_exit(usertok, line);
				break;
			case 1:
				chdir(usertok[1]);
				return (1);
			case 2:
				manage_help();
				return (1);
			case 3:
				print_env();
				return (1);
			default:
				break;
			}
		}
		i++;
	}
	return (0);
}
