#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
 * _printf - produces output according to a format
 * @format: a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char *str_arg;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					str_arg = va_arg(args, char *);
					if (str_arg == NULL)
					{
						str_arg = "(null)";
					}
					printed_chars += print_str(str_arg);
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				case 'd':
				case 'i':
					printed_chars += print_number(va_arg(args, int));
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * print_str - prints a string
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int print_str(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		count += _putchar(str[i]);
	}

	return (count);
}

/**
 * print_number - prints a number
 * @n: the number to print
 *
 * Return: the number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_number(num / 10);
	}

	count += _putchar((num % 10) + '0');

	return (count);
}

