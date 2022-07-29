#ifndef PRINTF_H
#define PRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
int _putchar(char);
int _putchar_s(char *s);
int _printf(const char *format, ...);

/**
 *struct print_function - Struct print
 *@c: The format specification
 *@f: The function associated
 */
typedef struct print_function
{
	char c;
	int (*f)(va_list);
} pfunc_t;

/* ############## MAP FUNCTION ################ */
int (*get_print_function(char a))(va_list);

/* ################ USE CASES ################# */
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_decimal(va_list);
int print_unsigned_decimal(va_list);
int print_binary(va_list);
int print_octal(va_list);
int print_hex(va_list);
int print_upper_hex(va_list);

/* ################## UTILS ################### */
int recursive_number(unsigned int, unsigned int, char *);
unsigned int make_abs(int);
#endif
