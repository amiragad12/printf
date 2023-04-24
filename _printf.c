#include "main.h"

/**
 * _printf - prints a formatted string to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0, count = 0;
	char *temp;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					temp = va_arg(args, char *);
					if (!temp)
						temp = "(null)";
					while (temp[j])
					{
						count += _putchar(temp[j]);
						j++;
					}
					j = 0;
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += print_number(va_arg(args, int));
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/**
 * print_number - prints a number
 * @n: The number to print
 *
 * Return: The number of digits printed
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n / 10)
		count += print_number(n / 10);

	count += _putchar(n % 10 + '0');

	return (count);
}


