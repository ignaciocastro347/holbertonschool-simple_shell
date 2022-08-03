#include "_string.h"
#include "shell.h"
#include <stdio.h>
extern char **environ;
void _print_env(void)
{
	int i = 0;
	for (; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}
