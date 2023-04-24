#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @par: the parameters struct
 * @ap: the argument pointer
 * Return: void
 */

void init_params(params_t *par, va_list ap)
{
	par->unsign = 0;
    par->width = 0;
	par->precision = UINT_MAX;
    par->h_modifier = 0;
	par->l_modifier = 0;
	par->plus_flag = 0;
	par->space_flag = 0;
	par->hashtag_flag = 0;
	par->zero_flag = 0;
	par->minus_flag = 0;	
	(void)ap;
}     

