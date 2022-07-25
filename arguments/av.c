#include <stdio.h>
int main(__attribute__((unused)) int ac, char **av)
{
	int i = 0;

	for (; av[i]; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
