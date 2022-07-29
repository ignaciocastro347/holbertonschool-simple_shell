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
/**
 * _strcat - concatenates two strings
 * @dest: var new string concatenate
 * @src: string to concatenate
 * Return: *dest
*/
char *_strcat(char *dest, char *src)
{
	size_t dest_len = _strlen(dest);
	size_t src_len = _strlen(src);
	size_t i;
	size_t all_len;
	char *tmp;

	all_len = dest_len + src_len + 1;
	tmp = malloc(all_len * sizeof(char));
	
	for (i = 0; i < dest_len; i++)
		tmp[i] = dest[i];

	for (i = 0 ; src[i] != '\0' ; i++)
			tmp[dest_len + i] = src[i];
	tmp[all_len -1] = '\0';
	return (tmp);
/* we need to free tmp outside this function*/
}
