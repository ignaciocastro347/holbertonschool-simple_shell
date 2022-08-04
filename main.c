#include "shell.h"
#include "_printf.h"
#include "_string.h"
/**
 * main - shell
 * Return: Always 0.
 */
int main()
{
	int int_mode = 0, status = 0;
	size_t len = 0;
	char *buffer = 0, *delim = " \t\n", **args = 0, *command = NULL;
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
		command = strtok(buffer, "\n");
		if (!command)
			continue;
		args = split(command, delim);
		free(buffer);
		buffer = NULL;

		status = execute_program(args);
		free_string_list(args);
		if (status != 0)
			return(status);
	}
	return (0);
}
int execute_program(char **args)
{
	int status = 0, wait_status;
	char *tmp = NULL, *paths = NULL;
	if (!args || !args[0])
		return (status);

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (access(args[0], F_OK) != 0)
		{
			return (print_not_found(args[0]));
		}
	}
	else
	{
		tmp = args[0];
		paths = _get_env("PATH");
		if (!paths)
		{
			if (access(args[0], F_OK) != 0)
			{
				status = print_not_found(tmp);
			}
			free_string_list(args);
			return(status);
		}
		args[0] = _which(paths, args[0]);
		if (!args[0])
		{
			if (access(args[0], F_OK) != 0)
			{
				status = print_not_found(tmp);
			}
			free(tmp);
			return(status);
		}
		free(tmp);
	}
	if (fork() == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error:");
		free_string_list(args);
	}
	else
		wait(&wait_status);
	return (0);
}

int print_not_found(char *cmd)
{
	write(STDERR_FILENO, "./hsh: 1: ", 10);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
	return (127);
}
