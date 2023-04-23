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
 * @is_neg: Lista of arguments
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

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buff: Buffer
 * @flag: Flags
 * @wid: width
 * @pre: Precision specifier
 * @len: Number length
 * @ch: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buff[],
	int flag, int wid, int pre,
	int len, char ch, char extra_c)
{
	int i, padd_start = 1;

	if (pre == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && wid == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (pre == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		buff[ind] = ch = ' '; /* width is displayed with padding ' ' */
	if (pre > 0 && pre < len)
		ch = ' ';
	while (pre > len)
		buff[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (wid > len)
	{
		for (i = 1; i < wid - len + 1; i++)
			buff[i] = ch;
		buff[i] = '\0';
		if (flag & F_MINUS && ch == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], len) + write(1, &buff[1], i - 1));
		}
		else if (!(flag & F_MINUS) && ch == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], len));
		}
		else if (!(flag & F_MINUS) && ch == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], len));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_neg: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flag: Flags specifiers
 * @wid: Width specifier
 * @pre: Precision specifier
 * @s: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_neg, int ind,
	char buff[],
	int flag, int wid, int pre, int s)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUFF_SIZE - ind - 1, i = 0;
	char ch = ' ';

	UNUSED(is_neg);
	UNUSED(s);

	if (pre == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (pre > 0 && pre < len)
		ch = ' ';

	while (pre > len)
	{
		buff[--ind] = '0';
		len++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		ch = '0';

	if (wid > len)
	{
		for (i = 0; i < wid - len; i++)
			buff[i] = ch;

		buff[i] = '\0';

		if (flag & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buff[ind], len) + write(1, &buff[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buff[0], i) + write(1, &buff[ind], len));
		}
	}

	return (write(1, &buff[ind], len));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
