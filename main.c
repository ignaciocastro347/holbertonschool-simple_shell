#include "shell.h"
#include "_printf.h"
#include "_string.h"
/**
 * main - shell
 * Return: Always 0.
 */
int main(void)
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
		args = split(command, delim);
		free(buffer);
		buffer = NULL;

		prepare_program(args);
		execute_program(args);
		free_string_list(args);
	}
	return (0);
}
/**
 * prepare_program -  look for full path if needed
 * @args: array of arguments
 */
void prepare_program(char **args)
{
	char *tmp = NULL, *paths = NULL;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (access(args[0], F_OK) != 0)
		{
			print_not_found(args[0]);
			free_string_list(args);
			exit(127);
		}
		return;
	}
	tmp = args[0];
	paths = _get_env("PATH");
	if (!paths)
	{
		print_not_found(tmp);
		free_string_list(args);
		exit(127);
	}
	args[0] = _which(paths, args[0]);
	if (!args[0])
	{
		print_not_found(tmp);
		free_string_list(args);
		free(tmp);
		exit(127);
	}
	free(tmp);
}
/**
 * execute_program - execute a command in a child process
 * @args: list of arguments
 */
void execute_program(char **args)
{
	int status;

	if (fork() == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error:");
		free_string_list(args);
	}
	else
		wait(&status);
}
/**
 * print_not_found - write not found error message in standar error
 * @cmd: command not found
 */
void print_not_found(char *cmd)
{
	write(STDERR_FILENO, "./hsh: 1: ", 10);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}
