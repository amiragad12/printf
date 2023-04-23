#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @l: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list l)
{
	int cur_i = *i + 1;
	int pre= -1;

	if (format[cur_i] != '.')
		return (pre);

	pre = 0;

	for (cur_i += 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			pre *= 10;
			pre += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			pre = va_arg(l, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (pre);
}
