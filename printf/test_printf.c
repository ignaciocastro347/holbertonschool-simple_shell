#include "main.h"
#include <stdio.h>
/**
 * main - main function to test printf
 * Return: Always 0
 */

int main(void)
{
	_printf("decimal %d\n", -47);
	_printf("unsigned decimal %u\n", -47);
	_printf("binary %b\n", 47);
	_printf("octal %o\n", 47);
	_printf("hex %x\n", 47);
	_printf("upper hex %X\n", 47);
	return (0);
}
