#include "_string.h"
/**
 * strlen - returns lenght of a string
 * @s: string
 * Return: return lenght
*/
int _strlen(char *s)
{
	int count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: comparission
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strdup - Duplicate a string
 * @str: - string original
 * Return: null or copy of the string
*/
char *_strdup(char *str)
{
	int size = 0, count = 0;
	char *copy = NULL;

	if (!str)
		return (NULL);
	size = _strlen(str);
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	for (count = 0; count < size; count++)
		copy[count] = str[count];
	copy[count] = '\0';
	return (copy);
}

/**
 * _strcat - concatenates two strings
 * @dest: var new string concatenate
 * @src: string to concatenate
 * Return: *dest
*/
char *_strcat(char *dest, char *src)
{
	size_t dest_len = 0;
	size_t src_len = 0;
	size_t i = 0, all_len = 0;

	if (dest)
		dest_len = _strlen(dest);
	if (src)
		src_len = _strlen(src);

	all_len = dest_len + src_len + 1;
	dest = realloc(dest, all_len);
	if (!dest)
		return (NULL);
	for (i = 0 ; src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[all_len -1] = '\0';
	
	return (dest);
	/* Remember to free this return value */
}
