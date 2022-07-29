#include "hstrdup.h"
#include <stdio.h>
int main(void)
{
char *s1 = "Hola mundo mundial";
char *dupli;

dupli = _strdup(s1);

printf("Tu duplicado es este: %s\n", dupli);
free(dupli);
return (0);
}
