#include "main.h"

/**
 * print_string - prints a string
 * @args: the variadic argument list
 *
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int printed_chars = 0;

	if (s == NULL)
		s = "(null)";

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		printed_chars++;
	}

	return (printed_chars);
}

