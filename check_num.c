#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @par: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *par)
{
	unsigned int i = _strlen(str);
	int neg = (!par->unsign && *str == '-');

	if (!par->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (par->precision != UINT_MAX)
		while (i++ < par->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!par->minus_flag)
		return (print_number_right_shift(str, par));
	else
		return (print_number_left_shift(str, par));
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @par: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *par)
{
	unsigned int n = 0, neg, negg, i = _strlen(str);
	char pad_char = ' ';

	if (par->zero_flag && !par->minus_flag)
		pad_char = '0';
	neg = negg = (!par->unsign && *str == '-');
	if (neg && i < par->width && pad_char == '0' && !par->minus_flag)
		str++;
	else
		neg = 0;

	if (par->plus_flag && !negg && !par->unsign)
		n += _putchar('+'), i++;
	else if (par->space_flag && !negg && !par->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < par->width)
		n += _putchar(pad_char);
	return (n);
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @par: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *par)
{
	unsigned int n = 0, neg, negg, i = _strlen(str);
	char pad_char = ' ';

	if (par->zero_flag && !par->minus_flag)
		pad_char = '0';
	neg = negg = (!par->unsign && *str == '-');
	if (neg && i < par->width && pad_char == '0' && !par->minus_flag)
		str++;
	else
		neg = 0;
	if ((par->plus_flag && !negg) ||
		(!par->plus_flag && par->space_flag && !negg))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (par->plus_flag && !negg && pad_char == '0' && !par->unsign)
		n += _putchar('+');
	else if (!par->plus_flag && par->space_flag && !negg &&
		!par->unsign && par->zero_flag)
		n += _putchar(' ');
	while (i++ < par->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (par->plus_flag && !negg && pad_char == ' ' && !par->unsign)
		n += _putchar('+');
	else if (!par->plus_flag && par->space_flag && !negg &&
		!par->unsign && !par->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

