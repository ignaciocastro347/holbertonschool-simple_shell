#include "string.h"
#include <stdio.h>
int main(void)
{
    int count;
    char *str = "1234567890aassasasasd";
    count = _strlen(str);
    printf("probando _strlen %d\n", count);
    return (0);
}