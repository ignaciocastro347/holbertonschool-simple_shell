#include "main.h"
/**
 * _strlen - returns lenght of a string
 * @s: string
 * Return: return lenght
*/
int _strlen(char *s)
{
	int count;
	count = 0;
		while (*s != '\0')
		{
			count++;
			s++;
		}
	return (count);
}