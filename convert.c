#include "main.h"

/**
 * print_address - prints address
 * @ap: argument pointer
 * @par: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list ap, params_t *par)
{
	unsigned long int i = va_arg(ap, unsigned long int);
	char *str;

	if (!i)
		return (_puts("(nil)"));

	str = convert(i, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, par);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, par));
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @par: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list ap, params_t *par)
{
	unsigned long l;

	if (par->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (par->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	par->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, par), par));
}

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @bas: base
 * @flag: argument flags
 * @par: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int bas, int flag, params_t *par)
{
	static char *arr;
	static char buff[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)par;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % bas];
		n /= bas;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

