#include "ft_printf.h"

char	*create_fe(t_scheme *scheme, va_list ptr)
{
	char		*str;
	long double	number;

	number = get_f(scheme, ptr);
	if (IS_F(scheme->type))
		str = create_float(scheme, number);
	else if (IS_E(scheme->type))
		str = create_exponent(scheme, number);
	return(str);
}