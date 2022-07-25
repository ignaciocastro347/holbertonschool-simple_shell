#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *line = 0;
	size_t len = 0;

	printf("$ ");
	while ((getline(&line, &len, stdin)) != 1)
	{
		printf("This is what you put: %s", line);
		printf("$ ");
	}
	return (0);
}
