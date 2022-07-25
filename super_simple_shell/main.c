#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - executes the command ls -l /tmp in 5 different child processes
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	(void) argc;
	int status;

	if (fork() == 0)
	{
		printf("From child\n");
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
		printf("end of child\n");
	}
	return (0);
}
