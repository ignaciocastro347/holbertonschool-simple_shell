#include "hstrdup.h"
#include <stdlib.h>
#include <string.h>
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
/**
 * _strdup - Duplicate a string
 * @str: - string original
 * Return: null or copy of the string
*/
char *_strdup(char *str)
{
	int size;
	char *copy;
	int count;

	if (str == NULL)
	{
		return (NULL);
	}
	size = _strlen(str);
	copy = (char *)malloc(sizeof(char) * size + 1);
	if (copy == NULL)
	{
		return ((char *)NULL);
	}
	for (count = 0; count < size; count++)
	{
		copy[count] = str[count];
	}
return (copy);
}
