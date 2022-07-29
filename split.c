#include "shell.h"
/**
 * split - create an array of strings from a string separated by chars
 * @buffer: string value to delimit
 * @delim: string with chars which ar delimiters
 * Return: array of string
 */
char **split(char *buffer, char *delim)
{
	char **list = NULL;
char *token = 0;
	char *dbuffer;
	int i = -1;

	if (!buffer)
		return (NULL);
	dbuffer = strdup(buffer);
	token = strtok(dbuffer, delim);
	while (token)
	{
		i++;
		list = realloc(list, sizeof(char *) * (i + 1));
		if (!list)
			return (NULL);
		list[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	i++;
	list = realloc(list, sizeof(char *) * (i + 1));
	list[i] = NULL;
	free(dbuffer);
	return (list);
}
