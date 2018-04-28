/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:48:05 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/16 15:48:07 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t			double_to_int(long double number)
{
	number += 0.00001;
	return ((intmax_t)number);
	// int		i;

	// i = 0;
	// while (number > 0)
	// {
	// 	number -= 0.1;
	// 	i++;
	// }
	// return (i / 10);
}

char		*create_float(t_scheme *scheme, long double number)
{
	char	*integer;
	char	*line;
	int		i;
	int		len;

	//integer = ft_itoa(number);
	integer = ft_itoa(double_to_int(number));
	len = ft_strlen(integer);
	line = ft_strnew(len + scheme->precision + (scheme->precision ? 1 : 0));
	ft_strcpy(line, integer);
	line[len] = scheme->precision ? '.' : '\0';
	number = number > 0 ? number : -number;
	number -= double_to_int(number);
	i = 1;
	while (i <= scheme->precision)
	{
		number *= 10;
		line[len + i] = '0' + double_to_int(number);
		number -= double_to_int(number);
		i++;
	}
	free(integer);
	return (line);
}

char		*format_exponent(int expo)
{
	char		*res;
	// char		*line;
	// int			pos;
	// int			len;

	// pos = expo < 0 ? 0 : 1;
	// expo = expo < 0 ? -expo : expo;
	// len = 3;
	res =  ft_itoa(expo);
	// while (expo > 99)
	// {
	// 	len++;
	// 	expo /= 10;
	// }
	// if ((line = ft_strnew(len)))
	// {
	// 	line[0] = pos ? '+' : '-';
	// 	pos = 1;
	// 	if (ft_strlen(res) < 2)
	// 		line[pos++] = '0';
	// 	ft_strcpy(line + pos, res);
	// }
	// free(res);
	// return (line);
	 return(res);
}

int			find_expo(long double *number)
{
	int expo;

	expo = 0;
	while (*number >= 10)
	{
		*number /= 10;
		expo += 1;
	}
	while (*number < 1)
	{
		*number *= 10;
		expo -= 1;
	}
	return (expo);
}

char		*create_exponent(t_scheme *scheme, long double number)
{
	int		expo;
	char	*mantissa;
	char	*exponent;
	//char	*line;
	//size_t	len;

	expo = find_expo(&number);
	mantissa = create_float(scheme, number);
	//(void)expo;
	exponent = format_exponent(expo);
	// len = ft_strlen(mantissa);
	// if ((line = ft_strnew(len + ft_strlen(exponent) + 1)))
	// {
	// 	ft_strcpy(line, mantissa);
	// 	line[len] = 'e';
	// 	ft_strcpy(line + len + 1, exponent);
	// }
	// free(mantissa);
	// free(exponent);
	(void)exponent;
	return (mantissa);
}
