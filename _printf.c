#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: the format string
 * @...: variadic arguments
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = parse_format(format, args);
	va_end(args);

	return (printed_chars);
}


