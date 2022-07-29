#include "_printf.h"
/**
 * recursive_number - prints a number recursively
 * @n: decimal
 * @base: base
 * @digits: string with digits to use
 * Return: the amount of decimal numbers
 */
int recursive_number(unsigned int n, unsigned int base, char *digits)
{
	int sum;

	if (n > (base - 1))
	{
		sum = recursive_number(n / base, base, digits);
		_putchar(digits[n % base]);
		return (sum + 1);
	}
	_putchar(digits[n]);
	return (1);
}
