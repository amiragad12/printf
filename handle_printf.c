#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @f: Formatted string in which to print the arguments.
 * @l: List of arguments to be printed.
 * @ind: ind.
 * @buff: Buffer array to handle print.
 * @flag: Calculates active flags
 * @wid: get width.
 * @pre: Precision specification
 * @s: Size specifier
 *
 * Return: 1 or 2;
 */
int handle_print(const char *f, int *ind, va_list l, char buff[],
	int flag, int wid, int pre, int s)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (f[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(l, buff, flag, wid, pre, s));

	if (fmt_types[i].fmt == '\0')
	{
		if (f[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (f[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (wid)
		{
			--(*ind);
			while (f[*ind] != ' ' && f[*ind] != '%')
				--(*ind);
			if (f[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &f[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

