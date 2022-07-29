#include "_printf.h"
/**
 * print_binary - print a binary number
 * @list: va_list value
 * Return: the amount of binary numbers
 */
int print_binary(va_list list)
{
	return (recursive_number(va_arg(list, int), 2, "01"));
}
/**
 * print_octal - print a octal number
 * @list: va_list value
 * Return: the amount of octal numbers
 */
int print_octal(va_list list)
{
	return (recursive_number(va_arg(list, int), 8, "01234567"));
}
/**
 *print_hex - print a hexadecimal number
 * @list: va_list value
 * Return: the amount of hexadecimal numbers
 */
int print_hex(va_list list)
{
	return (recursive_number(va_arg(list, int), 16, "0123456789abcdef"));
}
/**
 *print_upper_hex - print a hexadecimal number with uppercase letters
 * @list: va_list value
 * Return: the amount of hexadecimal numbers
 */
int print_upper_hex(va_list list)
{
	return (recursive_number(va_arg(list, int), 16, "0123456789ABCDEF"));
}
