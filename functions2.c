#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @typ: List a of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	char extra_c = 0, ch = ' ';
	int ind = BUFF_SIZE - 2, len = 2, ch_start = 1; 
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(typ, void *);

	UNUSED(wid);
	UNUSED(s);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(pre);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		ch = '0';
	if (flag & F_PLUS)
		extra_c = '+', len++;
	else if (flag & F_SPACE)
		extra_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buff, ind, len,
		wid, flag, ch, extra_c, ch_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @typ: Lista of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	int i = 0, offset = 0;
	char *str = va_arg(typ, char *);

	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre);
	UNUSED(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buff, i + offset);

		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @typ: Lista of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(s);

	str = va_arg(typ, char *);

	if (str == NULL)
	{
		UNUSED(pre);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @typ: Lista of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typ, char *);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

