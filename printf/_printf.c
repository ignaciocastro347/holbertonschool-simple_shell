#include "_printf.h"
#include <stdarg.h>

/**
 * _printf - main function of printf
 * @format: string value to print and specify type of next args
 * Return: amount of printed character
 */
int _printf(const char *format, ...)
{
	int i = 0, sum = 0;
	va_list list;
	int (*pr)(va_list);

	if (!format)
		return (-1);
	va_start(list, format);
	for (; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				if (i == 1)
					return (-1);
				break;
			}
			pr = get_print_function(format[i]);
			if (pr)
				sum += pr(list);
			else
			{
				_putchar('%');
				_putchar(format[i]);
				sum += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			sum++;
		}
	}
	va_end(list);
	return (sum);
}
