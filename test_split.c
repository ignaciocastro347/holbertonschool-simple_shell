#include "shell.h"

int main(void)
{
	char *str = "askd askjd akjsd kajs dkjas djk askjd jkas da sjd";
	char **argv;
	int i = 0;

	argv = split(str, " \n\t");
	while (argv[i])
		printf("%s\n", argv[i++]);

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
	return (0);
}
