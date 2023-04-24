#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int sum = 0;
	va_list ap;
	char *c, *start;

	params_t par = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))/* checking for NULL char */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_params(&par, ap);
		if (*c != '%')/*checking for the % specifier*/
		{
			sum += _putchar(*c);
			continue;
		}
		start = c;
		c++;
		while (get_flag(c, &par)) /* while char at p is flag character */
		{
			c++; /* next character */
		}
		c = get_width(c, &par, ap);
		c = get_precision(c, &par, ap);
		if (get_modifier(c, &par))
			c++;
		if (!get_specifier(c))
			sum += print_from_to(start, c,
					par.l_modifier || par.h_modifier ? c - 1 : 0);
		else
			sum += get_print_func(c, ap, &par);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
