#include "main.h"
/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags.
 * @wid: get width.
 * @pre: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buff[],
	int flag, int wid, int pre, int s)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char ch = ' ';

	UNUSED(pre);
	UNUSED(s);

	if (flag & F_ZERO)
		ch = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (wid > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < wid - 1; i++)
			buff[BUFF_SIZE - i - 2] = ch;

		if (flag & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - i - 1], wid - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], wid - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_neg: List of arguments
 * @ind: char types.
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: get width.
 * @pre: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_neg, int ind, char buff[],
	int flag, int wid, int pre, int s)
{
	int len = BUFF_SIZE - ind - 1;
	char ch = ' ', extra_ch = 0;

	UNUSED(s);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		ch = '0';
	if (is_neg)
		extra_ch = '-';
	else if (flag & F_PLUS)
		extra_ch = '+';
	else if (flag & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buff, flag, wid, pre,
		len, ch, extra_ch));
}
