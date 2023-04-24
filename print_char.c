#include "main.h"

/**
 * print_char - prints a character
 * @args: the variadic argument list
 *
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);

	return (1);
}
