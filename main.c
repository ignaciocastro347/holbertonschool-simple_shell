#include "shell.h"
#include "_printf.h"
#include "_string.h"
/**
 * main - shell
 * Return: Always 0.
 */
int main()
{
	int int_mode = 0;
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
		/*if (!buffer[0])
		{
			free(buffer);
			continue;
		}*/
		args = split(command, delim);
		free(buffer);
		buffer = NULL;

		execute_program(args);
		free_string_list(args);
	}
	return (0);
}
void execute_program(char **args)
{
	int status;
	char *tmp = NULL, *paths = NULL;

	if (!args || !args[0])
		return;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (access(args[0], F_OK) != 0)
		{
			write(STDERR_FILENO, "./hsh: 1: ", 10);
			write(STDERR_FILENO, args[0], _strlen(args[0]));
			write(STDERR_FILENO, ": not found\n", 12);
			return;
		}
	}
	else
	{
		tmp = args[0];
		paths = _get_env("PATH");
		if (!paths)
		{
			free(tmp);
			exit(127);
		}
		args[0] = _which(paths, args[0]);
		if (!args[0])
		{
			write(STDERR_FILENO, "./hsh: 1: ", 10);
			write(STDERR_FILENO, tmp, _strlen(tmp));
 			write(STDERR_FILENO, ": not found\n", 12);
			free(tmp);
			return;
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
		wait(&status);
}
