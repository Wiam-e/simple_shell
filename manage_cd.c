#include "shell.h"

/**
 * cd_pwd - changes the current working directory
 * @args: arguments
 */

void cd_pwd(char **args)
{
	char **directories = NULL, *oldpwd = NULL, *home = NULL;

	if (args[1] == NULL)
	{
		home = get_envi("HOME");
		if (home == NULL)
		{
			write(STDERR_FILENO, "cd: HOME not set\n", 17);
			return;
		}
		directories = malloc(sizeof(char *) * 2);
		if (directories == NULL)
			return;
		directories[0] = home;
		directories[1] = NULL;
	}
	else if (_strncmp(args[1], "-", 1) == 0)
	{
		oldpwd = get_envi("OLDPWD");
		if (oldpwd == NULL)
		{
			write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
			return;
		}
		directories = malloc(sizeof(char *) * 2);
		if (directories == NULL)
			return;
		directories[0] = oldpwd;
		directories[1] = NULL;
	}
	else
	{
		directories = malloc(sizeof(char *) * 2);
		if (directories == NULL)
			return;
		directories[0] = args[1];
		directories[1] = NULL;
	}
	ch_directory(directories, args[0]);
	free(directories);
}

/**
 * ch_directory - changes the current working directory
 * @directories: directories to change to
 * @cmd: name of the command
 */

void ch_directory(char **directories, char *cmd)
{
	char *pwd = getcwd(NULL, 0);

	if (chdir(directories[0]) == -1)
	{
		print_error(cmd, 0, directories[0], "can't cd to ");
		return;
	}
	else
{
		free(pwd);
	}
}
