#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - executes the command ls -l /tmp in 5 different child processes
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int status, i;

	for (i = 0; i < 5; i++)
	{
		if (fork() == 0)
		{
			printf("From child No: %d\n", i + 1);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
			printf("end of child No: %d\n", i + 1);
		}
	}
	return (0);
}
