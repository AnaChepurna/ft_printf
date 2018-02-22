#include "ft_printf.h"

long double		get_f(t_scheme *scheme, va_list ptr)
{
	long double number;

	long double	number;
	char		*line;

	if (scheme->size == 'D')
		number = va_list(ptr, long double);
	else
		number = va_list(ptr, double);
	if (!scheme->precision)
		scheme->precision = 6;
	return(number);
}