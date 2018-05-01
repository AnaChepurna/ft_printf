/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_floats2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:45:27 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/20 11:06:10 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_teil(long double number, int base)
{
	int		len;

	len = 1;
	while (len < 14 && number > 0)
	{
		number *= base;
		number -= (intmax_t)number;
		len++;
	}
	return (len);
}

char	*teil_ftoa(long double number, int precision, int base)
{
	char		*line;
	int			i;
	int			len;
	const char	*mask = "0123456789abcdefghijklmnopqrstuvwxyz";

	len = (precision < 0) ? count_teil(number, base) : precision + 1;
	if ((line = ft_strnew(len)) && len)
	{
		i = 0;
		line[i++] = '.';
		while (i < len)
		{
			number *= base;
			line[i] = mask[(intmax_t)number];
			number -= (intmax_t)number;
			i++;
		}
	}
	return (line);
}

char	*ft_ftoa(long double number, int precision, int base)
{
	char		*head;
	char		*teil;
	char		*line;
	long double num;

	num = (intmax_t)number;
	head = ft_itoa_base(num, base);
	number -= num;
	teil = (precision > -1 || number != 0) ?
	teil_ftoa(number, precision, base) : ft_strdup("");
	line = ft_strjoin(head, teil);
	free(head);
	free(teil);
	return (line);
}

char	*compile_hexfloat(char *mantissa, char *exponent, int sign)
{
	char	*line;
	size_t	len_m;

	len_m = ft_strlen(mantissa);
	if ((line = ft_strnew(len_m + 2 + ft_strlen(exponent))))
	{
		ft_strcpy(line, mantissa);
		ft_strcpy(line + len_m, "p");
		line[len_m + 1] = sign ? '-' : '+';
		ft_strcpy(line + len_m + 2, exponent);
	}
	free(mantissa);
	free(exponent);
	return (line);
}

char	*create_hexfloat(t_scheme *scheme, long double number)
{
	int		rank;
	char	*mantissa;
	char	*exponent;
	int		sign;

	rank = 0;
	while (number >= 2)
	{
		number = number / (double)2;
		rank++;
	}
	while (number < 0)
	{
		number = number * (double)2;
		rank--;
	}
	sign = rank < 0 ? 1 : 0;
	mantissa = ft_ftoa(number, scheme->precision, 16);
	exponent = ft_itoa_base(rank, 10);
	return (compile_hexfloat(mantissa, exponent, sign));
}
