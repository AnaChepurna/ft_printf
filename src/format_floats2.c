/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_floats2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:45:27 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/16 15:45:29 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_power(double long *number, int *sign)
{
	int			p;
	long double buf;

	sign[0] = 0;
	if (*number < 0)
	{
		*number = *number * -1;
		sign[0] = 1;
	}
	p = 1;
	while (*number >= 2)
	{
		sign[1] = 0;
		if ((buf = *number / ++p) < 2)
			*number = buf;
	}
	while (*number < 1)
	{
		sign[1] = 1;
		if ((buf = *number * ++p) >= 1)
			*number = buf;
	}
	return (p);
}

int		count_teil_hex(long double number)
{
	int		len;

	len = 1;
	while (len < 14 && number > 0)
	{
		number *= 16;
		number -= double_to_int(number);
		len++;
	}
	return (len);
}

char	*teil_hex(long double number, int precision)
{
	char		*line;
	int			i;
	int			len;
	const char	*mask = "0123456789abcdef";

	len = count_teil_hex(number);
	if (precision >= 0 && len > precision)
		len = precision;
	if (len && (line = ft_strnew(len)))
	{
		i = 0;
		line[i++] = '.';
		while (i < len)
		{
			number *= 16;
			line[i] = mask[double_to_int(number)];
			number -= double_to_int(number);
			i++;
		}
	}
	return (line);
}

char	*ftoa_hex(long double number, int precision)
{
	char	*head;
	char	*teil;
	char	*line;

	head = ft_itoa_base(number, 16);
	number = number > 0 ? number : -number;
	number -= (intmax_t)number;
	teil = teil_hex(number, precision);
	line = ft_strjoin(head, teil);
	free(head);
	free(teil);
	return (line);
}

char	*create_hexfloat(t_scheme *scheme, long double number)
{
	int		p;
	char	*power;
	char	*mantissa;
	char	*line;
	int		sign[2];

	p = find_power(&number, sign);
	mantissa = ftoa_hex(number, scheme->precision);
	power = ft_itoa_base(p, 16);
	p = ft_strlen(mantissa);
	if ((line = ft_strnew(p + ft_strlen(power) + 4 + sign[0])))
	{
		if (sign[0])
			line[0] = '-';
		ft_strcpy(line + sign[0], "0x");
		ft_strcpy(line + sign[0] + 2, mantissa);
		ft_strcpy(line + sign[0] + 2 + p, "");
		line[sign[0] + 2 + p] = 'p';
		line[sign[0] + 3 + p] = sign[1] ? '-' : '+';
		ft_strcpy(line + sign[0] + 4 + p, power);
	}
	free(mantissa);
	free(power);
	return (line);
}
