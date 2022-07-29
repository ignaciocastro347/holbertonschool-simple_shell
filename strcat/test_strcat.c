#include "main.h"
#include <stdio.h>
int main(void)
{
	char *original = "hola";
	char *add = " mundoasd asdas asdasdasdd";
	char *test;
	test = _strcat(original, add);
	printf("Concatenada: %s\n", test);
	free(test);
	return (0);
}
