#include "_string.h"
#include "shell.h"
#include "_printf.h"

char *_which(char *path, char *cmd)
{
	int i = 0;
	char *full_path = NULL;
	char **path_list = NULL;

	if (!path || !cmd)
		return (NULL);
	path_list = split(path, ":");
	free(path);
	for (i = 0; path_list && path_list[i]; i++)
	{
		full_path = _strcat(full_path, path_list[i]);
		if (!full_path)
			return (NULL);
		full_path = _strcat(full_path, "/");
		if (!full_path)
			return (NULL);
		full_path = _strcat(full_path, cmd);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK) == 0)
		{
			free_string_list(path_list);
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
	}
	free_string_list(path_list);
	return (NULL);
}

char *_get_env (char *str)
{
	int i = 0;
	char *key = NULL, *value = NULL;
	char *env_dup = NULL;

	for(i = 0; environ[i]; i++)
	{
		env_dup = _strdup(environ[i]);
		key = strtok(env_dup, "=");
		if(_strcmp(key, str) == 0)
		{
			value = _strdup(strtok(NULL, "="));
			free(env_dup);
			return(value);
		}
		free(env_dup);
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
