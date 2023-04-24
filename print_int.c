#include "main.h"

/**
 * print_int - prints an integer
 * @args: the variadic argument list
 *
 * Return: the number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int printed_chars = 0;

	if (n < 0)
	{
		_putchar('-');
		printed_chars++;
		n = -n;
	}

	if (n / 10)
		printed_chars += print_int(n / 10);

	_putchar(n % 10 + '0');
	printed_chars++;

	return (printed_chars);
}

