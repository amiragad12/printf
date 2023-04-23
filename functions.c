#include "main.h"
/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @typ: Lista of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width.
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int c;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre);
	UNUSED(s);

	n = va_arg(typ, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, c = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			c++;
		}
	}
	return (c);
}
/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @typ: Lista of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width.
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = convert_size_number(n, s);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_neg, i, buff, flag, wid, pre, s));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @typ: List a of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width.
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	int len = 0, i;
	char *str = va_arg(typ, char *);

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre);
	UNUSED(s);
	if (str == NULL)
	{
		str = "(null)";
		if (pre >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (pre >= 0 && pre < len)
		len = pre;

	if (wid > len)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (wid);
		}
	}

	return (write(1, str, len));
}
/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @typ: List a of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: Width
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	char c = va_arg(typ, int);

	return (handle_write_char(c, buff, flag, wid, pre, s));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @typ: Lista of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width.
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	UNUSED(typ);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(pre);
	UNUSED(s);
	return (write(1, "%%", 1));
}
