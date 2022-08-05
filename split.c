#include "shell.h"
#include "_string.h"
/**
 * split - create an array of strings from a string separated by chars
 * @buffer: string value to delimit
 * @delim: string with chars which ar delimiters
 * Return: array of string
 */
char **split(char *buffer, char *delim)
{
	char **list = NULL;
	char *token = NULL;
	char *dbuffer = NULL;
	int i = 0, amount_tokens = 0;

	if (!buffer)
		return (NULL);
	amount_tokens = count_tokens(buffer, delim);
	list = malloc(sizeof(char *) * (amount_tokens + 1));

	if (!list)
		return (NULL);
	dbuffer = _strdup(buffer);
	token = strtok(dbuffer, delim);
	while (token)
	{
		list[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	list[i] = NULL;
	free(dbuffer);
	return (list);
}
/**
 * count_tokens - Count tokens
 * @str: String
 * @delims: Delimiters
 * Return: Number of tokens
*/
int count_tokens(char *str, char *delims)
{
	int counter = 0, i = 0, j = 0;
	int prev_is_delim = 0;

	for (; str[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (str[i] == delims[j])
			{
				if (!prev_is_delim)
				{
					if (i != 0)
						counter++;
					prev_is_delim = 1;
				}
				break;
			}
			else if (!delims[j + 1] && prev_is_delim)
				prev_is_delim = 0;
		}
	}
	if (i != 0 && !prev_is_delim)
		counter++;
	return (counter);
}
