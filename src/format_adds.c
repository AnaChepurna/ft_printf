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

void	stabilize_oux(t_scheme *scheme, uintmax_t number)
{
	if (!scheme->precision && !number && (IS_O(scheme->type)) && scheme->flag & F_HASH)
		scheme->precision = 1;
	else if (scheme->len > scheme->precision && number)
		scheme->precision = -1;
	if (scheme->flag & F_HASH && (IS_O(scheme->type)) && number)
	{
		scheme->flag += ALT1;
		scheme->len++;
	}
	else if (scheme->flag & F_HASH && (IS_X(scheme->type)) && number)
	{
		scheme->flag += ALT1 + ALT2;
		scheme->len += 2;
	}
	if (scheme->flag & F_HASH && (IS_O(scheme->type)) && scheme->precision > -1 && number)
	{
		scheme->len--;
		scheme->precision--;
	}
}

// int		get_size(t_scheme *scheme)
// {
// 	if (!scheme->size)
// 		return (sizeof(unsigned int));
// 	if (scheme->size == 'h')
// 		return (sizeof(unsigned short));
// 	if (scheme->size == 'h' + 'h')
// 		return (sizeof(unsigned char));
// 	if (scheme->size == 'l')
// 		return (sizeof(unsigned long int));
// 	if (scheme->size == 'l' + 'l')
// 		return (sizeof(unsigned long long int));
// 	if (scheme->size == 'z')
// 		return (sizeof(size_t));
// 	if (scheme->size == 'j')
// 		return (sizeof(uintmax_t));
// 	else
// 		exit(1);
// }

// void	binary_precision(t_scheme *scheme, char **str)
// {
// 	char	*buf;
// 	int		size;
// 	size_t	i;

// 	size = get_size(scheme);
// 	while (scheme->precision > size)
// 	{
// 		buf = ft_strjoin("00000000 ", *str);
// 		free(*str);
// 		*str = buf;
// 		size++;
// 	}
// 	i = 0;
// 	while (scheme->precision < size)
// 	{
// 		i += size > 1 ? 9 : 8;
// 		size--;
// 	}
// 	if (i)
// 	{
// 		buf = ft_strdup(*str + i);
// 		free(*str);
// 		*str = buf;
// 	}
// }

// void	binary_format(unsigned char	c, char **line, int space)
// {
// 	t_scheme	*scheme;
// 	char		*str;
// 	char		*buf;

// 	scheme = scheme_new();
// 	scheme->precision = 8;
// 	str = ft_itoa_base(c, 2);
// 	precision_number(scheme, &str);
// 	if (space)
// 	{
// 		buf = ft_strjoin(str, " ");
// 		free(str);
// 		str = buf;
// 	}
// 	buf = ft_strjoin(*line, str);
// 	free(*line);
// 	*line = buf;
// 	free(str);
// 	scheme_del(&scheme);
// }

// char	*create_wstr(wchar_t *ptr)
// {
// 	int		i;
// 	char	*res;

// 	i = 0;
// 	while (ptr[i])
// 	{
// 		if (!ft_isascii((int)ptr[i]))
// 			return (NULL);
// 		i++;
// 	}
// 	if ((res = ft_strnew(i)))
// 	{
// 		i = 0;
// 		while (ptr[i])
// 		{
// 			res[i] = (char)ptr[i];
// 			i++;
// 		}
// 	}
// 	return (res);
// }
