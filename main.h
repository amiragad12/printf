#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
//#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list l, char buff[], int flags, int wid, int pre, int s);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list typ, char buff[],
	int flag, int wid, int pre, int s);
int print_string(va_list typ, char buff[],
	int flag, int wid, int pre, int s);
int print_percent(va_list type, char buff[],
	int flag, int wid, int pre, int s);

/* Functions to print numbers */
int print_int(va_list typ, char buff[],
	int flag, int wid, int pre, int s);
int print_binary(va_list typ, char buff[],
	int flag, int wid, int pre, int s);
/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list l);
int get_precision(const char *format, int *i, va_list l);
int get_size(const char *format, int *i);
/* width handler */
int handle_write_char(char c, char buff[],
	int flag, int wid, int pre, int s);
int write_number(int is_neg, int ind, char buff[],
	int flag, int wid, int pre, int s);
/****************** UTILS ******************/
int is_digit(char);
long int convert_size_number(long int num, int s);

#endif /* MAIN_H */
