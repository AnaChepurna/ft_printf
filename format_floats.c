#include "ft_printf.h"

char		*create_float(t_scheme *scheme, long double number)
{
	char	*i;
	char	*f;
	char	*line;
	int		x;
	size_t	len;

	i = ft_itoa(number);
	x = scheme->precision + 1;
	number = number % 1;
	number = number > 0 ? number : -number;
	while (x--)
		number *= 10;
	f = ft_itoa(number);
	len = ft_strlen(i);
	if ((line = ft_strnew(len + scheme->precision + 1)))
	{
		ft_strcpy(line, i);
		line[len] = '.';
		ft_strcpy(line + len + 1, f);
		if ((x = (int)ft_strlen(f)) < scheme->precision)
			ft_memset(line + len + 1 + x, '0', scheme->precision - x);
	}
	free(i);
	free(f);
	return (line);
}