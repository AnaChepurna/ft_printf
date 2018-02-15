#include "ft_printf.h"

char		*create_float(t_scheme *scheme, long double number)
{
	char	*integer;
	char	*line;
	int		i;
	int		len;

	integer = ft_itoa(number);
	len = ft_strlen(integer);
	line = ft_strnew(len + i + scheme->precision);
	ft_strcpy(line, integer);
	line[len] = '.';
	number = number % 1;
	number = number > 0 ? number : -number;
	i = 0;
	while (i < scheme->precision)
	{
		number *= 10;
		line[len + i] = '0' + number;
	}
	free(integer);
	return (line);
}