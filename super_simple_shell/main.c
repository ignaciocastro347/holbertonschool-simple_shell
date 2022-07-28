#include "shell.h"
/**
 * main - shell
 * Return: Always 0.
 */
int main()
{
	int status;
	size_t len = 0;
	char *buffer = 0, *delim = " \t\n", **args;
	ssize_t getline_status = 1;

	while (getline_status != -1)
	{
		printf("#cisfun$ ");
		getline_status = getline(&buffer, &len, stdin);
		buffer = strtok(buffer, "\n");
		if (!buffer)
			continue;
		/* delimit buffer by delimiters */
		args = split(buffer, delim);
		/* create a child process */
		if (args && fork() == 0)
		{
			/* exec shell command, return error message if it fails */
			if (execve(args[0], args, NULL) == -1)
				perror("Error:");
			break;
		}
		else
		{
			/* wait until child process ends to continue */
			wait(&status);
		}
	}

	/* WE SHOULD HANDLE end-of-file (Ctrl+d, etc.) AND FREE ALLOCATED MEMORY
	 * BEFORE ENDING THE PROGRAM.
	 * - **arg
	 * - *buffer
	 */

	return (0);
}
