#include "_printf.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putchar_s - print a string using putchar
 * @s: The string to print
 * Return: amount of printed chars
 */
int _putchar_s(char *s)
{
	int i = 0;

	for (; s[i]; i++)
		_putchar(s[i]);
	return (i);
}
