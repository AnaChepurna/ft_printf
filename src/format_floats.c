#include "ft_printf.h"

char		*create_float(t_scheme *scheme, long double number)
{
	char	*integer;
	char	*line;
	int		i;
	int		len;

	integer = ft_itoa(number);
	len = ft_strlen(integer);
	line = ft_strnew(len + scheme->precision);
	ft_strcpy(line, integer);
	line[len] = '.';
	number -= (int)number;
	number = number > 0 ? number : -number;
	i = 1;
	while (i <= scheme->precision)
	{
		number *= 10;
		printf("%Lf. %i\n", number, (int)number);
		line[len + i] = '0' + number;
		number -= (int)number;
		i++;
	}
	free(integer);
	return (line);
}

char		*format_exponent(int expo)
{
	t_scheme	*scheme;
	char		*res;

	scheme = scheme_new();
	scheme->precision = 2;
	scheme->flag += F_PLUS;
	res = ft_itoa(expo);
	sign_number(scheme, &res);
	precision_number(scheme, &res);
	return (res);
}

int			find_expo(long double  *number)
{
	int expo;

	expo = 0;
	while (*number > 10)
	{
		*number /= 10;
		expo +=1;
	}
	while (*number < 0)
	{
		*number *= 10;
		expo -=1;
	}
	return (expo);
}

char		*create_exponent(t_scheme *scheme, long double number)
{
	int		expo;
	char	*mantissa;
	char	*exponent;
	char	*line;
	size_t	len;

	expo = find_expo(&number);
	mantissa = create_float(scheme, number);
	exponent = format_exponent(expo);
	len = ft_strlen(mantissa);
	if ((line = ft_strnew(len + ft_strlen(exponent) + 1)))
	{
		ft_strcpy(line, mantissa);
		line[len] = 'e';
		ft_strcpy(line + len + 1, exponent);
	}
	free(mantissa);
	free(exponent);
	return(line);
}