#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @st: the format string
 * @par: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
*/

char *get_precision(char *st, params_t *par, va_list ap)
{
	int i = 0;

	if (*st != '.')
		return (st);
	st++;
	if (*st == '*')
	{
		i = va_arg(ap, int);
		st++;
	}
	else
	{
		while (_isdigit(*st))
			i = i * 10 + (*st++ - '0');
	}
	par->precision = i;
	return (st);
}
