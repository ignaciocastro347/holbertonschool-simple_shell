#include "shell.h"
/**
 * free_string_list - free memory allocated in an array of strings
 * @list: array of strings
 * Return: 0 on success, 1 on failure
 */
int free_string_list(char **list)
{
	int i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
	return (0);
}
