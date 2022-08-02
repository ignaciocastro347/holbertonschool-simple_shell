#include "shell.h"
#include "_string.h"
extern char **environ;

char *_which (char *str)
{
	int i = 0;
	char *key = NULL;

	for(i = 0; environ[i]; i++)
	{
		key = strtok(environ[i], "=");
		if(_strcmp(key, str) == 0)
			return(strtok(NULL, "="));
	}
	return (NULL);
}
