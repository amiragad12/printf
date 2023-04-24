#include "main.h"

/**
 * parse_format - parses the format string and prints output
 * @format: the format string
 * @args: variadic arguments
 *
 * Return: the number of characters printed
 */
int parse_format(const char *format, va_list args)
{
	int i = 0, printed_chars = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			else if (format[i] == '%')
				printed_chars += _putchar('%');
			else if (format[i] == 'c')
				printed_chars += print_char(args);
			else if (format[i] == 's')
				printed_chars += print_string(args);
			else if (format[i] == 'd' || format[i] == 'i')
				printed_chars += print_int(args);
			else
				return (-1);
		}
		else
			printed_chars += _putchar(format[i]);
		i++;
	}

	return (printed_chars);
}

