#include "hmain.h"
/**
 * Split para que no joda
*/
int split(char ***dest, char *buffer, char *delim)
{
	char **list;
	char *token = '\0';
	int i = -1;

	token = strtok(buffer, delim);
	while (token)
	{
		i++;
		list = realloc(list, sizeof(char) * i);
		if (!dest)
			return (-1);
		list[i] = malloc(sizeof(char) * strlen(token));
		if (list[i])
			return(-1);
		list[i] = token;
		token = strtok(NULL, delim);
	}
	**dest = *list;
	return (0);
}
/**
 * Experimental solution to memory leak
*/
int main()
{
	int status;
	size_t len = 0;
	char *buffer = 0;
	char *delim = " \t\n";
	char **tempArgs;

	printf("#cisfun$ ");
	while ((getline(&buffer, &len, stdin)) != -1)
	{
		/* take first token */
		split(&tempArgs, buffer, delim);
		printf("%s", tempArgs[0]);
		/* create a child process */
		if (tempArgs && tempArgs[0] && fork() == 0)
		{
			/* exec shell command, return error message if it fails */
			if (execve(tempArgs[0], tempArgs, NULL) == -1)
				perror("Error:");
			break;
		}
		else
		{
			/* wait until child process ends to continue */
			wait(&status);
			free_grid(char **tempArgs);
			printf("#cisfun$ ");
		}
	}
	return (0);
}
