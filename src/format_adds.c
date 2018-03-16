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

int		get_size(t_scheme *scheme)
{
	if (!scheme->size)
		return (sizeof(unsigned int));
	if (scheme->size == 'h')
		return (sizeof(unsigned short));
	if (scheme->size == 'h' + 'h')
		return (sizeof(unsigned char));
	if (scheme->size == 'l')
		return (sizeof(unsigned long int));
	if (scheme->size == 'l' + 'l')
		return (sizeof(unsigned long long int));
	if (scheme->size == 'z')
		return (sizeof(size_t));
	if (scheme->size == 'j')
		return (sizeof(uintmax_t));
	else
		exit(1);
}

void	binary_format(unsigned char	c, char **line, int space)
{
	t_scheme	*scheme;
	char		*str;
	char		*buf;

	scheme = scheme_new();
	scheme->precision = 8;
	str = ft_itoa_base(c, 2);
	precision_number(scheme, &str);
	if (space)
	{
		buf = ft_strjoin(str, " ");
		free(str);
		str = buf;
	}
	buf = ft_strjoin(*line, str);
	free(*line);
	*line = buf;
	free(str);
	scheme_del(&scheme);
}
