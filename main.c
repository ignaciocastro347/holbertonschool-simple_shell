#include "shell.h"
#include "_printf.h"

/**
 * main - shell
 * Return: Always 0.
 */
int main()
{
	int int_mode = 0;
	size_t len = 0;
	char *buffer = 0, *delim = " \t\n", **args = 0;
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

		execute_program(buffer, args);
		free_string_list(args);
	}
	return (0);
}
void execute_program(char *buffer, char **args)
{
	int status;
	char *tmp = NULL;

	if (args && args[0])
	{
		/* Check if program name already starts with '/' */
		if (args[0][0] == '/')
		{
			if (access(args[0], F_OK) != 0)
			{
				_printf("This program does not exist!!!");
				return;
			}
		}
		else
		{
			/* Get full path of program and set it into args[0] */
			tmp = args[0];
			args[0] = _which(_get_env("PATH"), args[0]);
			if (!args[0])
			{
				_printf("Which no match\n");
				return;
			}
			free(tmp);
		}

		/* fork process and execute program */
		if (fork() == 0)
		{
			if (execve(args[0], args, environ) == -1)
				perror("Error:");
			free_string_list(args);
			free(buffer);
		}
		else
			wait(&status);
	}
}
