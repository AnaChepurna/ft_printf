#include "ft_printf.h"

char	*handle_naninf(long double number)
{
	if (number == INFINITY)
		return (ft_strdup("inf"));
	if (number == -INFINITY)
		return (ft_strdup("-inf"));
	if (isnan(number))
		return (ft_strdup("nan"));
	return (NULL);
}

char	*create_fe(t_scheme *scheme, va_list ptr)
{
	char		*str;
	long double	number;

	number = get_f(scheme, ptr);
	if (!(str = handle_naninf(number)))
	{
		if (IS_F(scheme->type))
			str = create_float(scheme, number);
		else if (IS_E(scheme->type))
			str = create_exponent(scheme, number);
	}
	return(str);
}