#include "ft_printf.h"

long double		get_f(t_scheme *scheme, va_list ptr)
{
	long double	number;

	if (scheme->type == 'D' || scheme->size == 'L')
		number = va_arg(ptr, long double);
	else
		number = va_arg(ptr, double);
	if (scheme->precision == -1)
		scheme->precision = 6;
	return(number);
}