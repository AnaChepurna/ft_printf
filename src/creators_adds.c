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
		else //if (IS_E(scheme->type))
			str = create_exponent(scheme, number);
		//lse
		//:	str = create_hexfloat(scheme, number);
		if ((scheme->flag & F_PLUS) || (scheme->flag & F_SPACE))
			sign_number(scheme, &str);
		if (scheme->width)
			width_number(scheme, &str);
	}
	return(str);
}

int		get_size(t_scheme *scheme)
{
	if (!scheme->size)
		return(sizeof(unsigned int));
	if (scheme->size == 'h')
		return(sizeof(unsigned short));
	if (scheme->size == 'h' + 'h')
		return(sizeof(unsigned char));
	if (scheme->size == 'l')
		return(sizeof(unsigned long int));
	if (scheme->size == 'l' + 'l')
		return(sizeof(unsigned long long int));
	if (scheme->size == 'z')
		return(sizeof(size_t));
	if (scheme->size == 'j')
		return(sizeof(uintmax_t));
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

char	*create_b(t_scheme *scheme, va_list ptr)
{
	uintmax_t		number;
	int				size;
	unsigned char	*str;
	char			*line;

	number = get_u(scheme, ptr);
	size = get_size(scheme);
	//printf("%s == %ju\n ^^^ whole number\n", ft_itoa_base(number, 2), number);
	//printf("%i\n", size);
	str = (unsigned char *)&number;
	line = ft_strdup("");
	while(--size >= 0)
		binary_format(str[size], &line, size != 0);
	if (scheme->width)
			width_number(scheme, &line);
	return (line);
}