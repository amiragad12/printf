#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @l: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list l)
{
	int cur_i;
	int wid = 0;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			wid *= 10;
			wid += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			wid = va_arg(l, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (wid);
}
