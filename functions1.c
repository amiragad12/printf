#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @typ: List a of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buff, flag, wid, pre, s));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @typ: Lista of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & F_HASH && init_num != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, flag, wid, pre, s));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @typ: Lista of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	return (print_hexa(typ, "0123456789abcdef", buff,
		flag, 'x', wid, pre, s));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @typ: Lista of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list typ, char buff[],
	int flag, int wid, int pre, int s)
{
	return (print_hexa(typ, "0123456789ABCDEF", buff,
		flag, 'X', wid, pre, s));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @typ: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @s: Size specifier
 * @s: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list typ, char map_to[], char buff[],
	int flag, char flag_ch, int wid, int pre, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, flag, wid, pre, s));
}

