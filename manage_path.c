#include "shell.h"
/**
  * con_path - Concatenate the path name and the program name
  * @pathname: The path name to concatenate with the program name
  * @progname: The program name to place in the path name
  * Return: The path name concatenated with the program name
  */
char *con_path(char *pathname, char *progname)
{
	int g_len = 0, th_len = 0, size = 0;

	g_len = _strlen(progname);
	th_len = _strlen(pathname);
	size = sizeof(char) * (g_len + th_len + 2);
	pathname = _realloc(pathname, (th_len + 1), size);
if (!pathname)
{
return (NULL);
}
	_strcat(pathname, "/");
	_strcat(pathname, progname);

	return (pathname);
}

/**
  * check_cmd - Checks if a command is found in the system
  * @cn: The command name to find in the system
  * Return: The path name of cmd, otherwise NULL (Fail)
  */
char *check_cmd(char *cn)
{
	char *env_path = NULL, **pathtok = NULL;
	int i = 0, ndeli = 0;
	struct stat sb;

	if (cn)
	{
		if (stat(cn, &sb) != 0 && cn[0] != '/')
		{
			env_path = get_envi("PATH");
			ndeli = delimiter(env_path, ":") + 1;
			pathtok = str_tok(env_path, ":", ndeli);

			while (pathtok[i])
			{
				pathtok[i] = con_path(pathtok[i], cn);

				if (stat(pathtok[i], &sb) == 0)
				{
					free(cn);
					cn = _strdbl(pathtok[i]);
					frees_get_env(env_path);
					free_token(pathtok);
					return (cn);
				}
				i++;
			}

			frees_get_env(env_path);
			free_token(pathtok);
		}

		if (stat(cn, &sb) == 0)
			return (cn);
	}

	free(cn);
	return (NULL);
}
