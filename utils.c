#include "_string.h"
#include "shell.h"
#include "_printf.h"

char *_which(char *path, char *cmd)
{
	int i = 0;
	char *full_path = NULL;
	char **path_list = NULL;

	if (!full_path || !path || !cmd)
		return (NULL);
	path_list = split(path, ":");
	for (i = 0; path_list && path_list[i]; i++)
	{
		full_path = _strcat(full_path, path_list[i]);
		full_path = _strcat(full_path, "/");
		full_path = _strcat (full_path, cmd);
		if (access(full_path, F_OK) == 0)
		{
			free(path_list);
			return (full_path);
		}
		free(full_path);
	}
	free(path_list);
	return (NULL);
}
char *_get_env (char *str)
{
	int i = 0;
	char *key = NULL;

	for(i = 0; environ[i]; i++)
	{
		key = strtok(environ[i], "=");
		if(_strcmp(key, str) == 0)
			return(strtok(NULL, "="));
	}
	return (NULL);
}
void print_new_line(int *mode)
{
	if (*mode || isatty(STDIN_FILENO))
	{
		_printf("#cisfun$ ");
		if (!mode)
			*mode = 1;
	}
}
