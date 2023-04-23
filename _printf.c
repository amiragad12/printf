#include "main.h"

void print_buffer(char buff[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_ch = 0;
	int flag, wid, pre, s, buff_ind = 0;
	va_list l;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(l, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buff, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_ch++;
		}
		else
		{
			print_buffer(buff, &buff_ind);
			flag = get_flags(format, &i);
			wid = get_width(format, &i, l);
			pre = get_precision(format, &i, l);
			s = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, l, buff,
				flag, wid, pre, s);
			if (printed == -1)
				return (-1);
			printed_ch += printed;
		}
	}

	print_buffer(buff, &buff_ind);

	va_end(l);
	return (printed_ch);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buff: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buff[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buff[0], *buff_ind);

	*buff_ind = 0;
}

