#include "shell.h"
#include "_printf.h"

void print_new_line(int *);
/**
 * main - shell
 * Return: Always 0.
 */
int main()
{
	int status = 0, int_mode = 0;
	size_t len = 0;
	char *buffer = 0, *delim = " \t\n", **args;
	ssize_t getline_status = 1;

	while (1)
	{
		print_new_line(&int_mode);
		getline_status = getline(&buffer, &len, stdin);
		if (getline_status == -1)
		{
			free(buffer);
			return (0);
		}
		buffer = strtok(buffer, "\n");
		if (!buffer)
		{
			free(buffer);
			continue;
		}
		args = split(buffer, delim);
		if (args && fork() == 0)
		{
			if (execve(args[0], args, environ) == -1)	
				perror("Error:");
			free_string_list(args);
			free(buffer); 
			break;
		}
		else
			wait(&status);
		free_string_list(args);
	}
	return (0);
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
