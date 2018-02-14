/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:54:16 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 18:18:14 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		sign_control(char *str)
{
	int		sign;

	sign = 0;
	if (*str == '-' || *str == '+' || *str == ' ' || *str == '0')
	{
		sign++;
		if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
			sign++;
	}
	return (sign);
}

void			precision_number(t_scheme *scheme, char **str)
{
	int		len;
	char	*line;
	int		sign;

	sign = sign_control(*str);
	len = (int)ft_strlen(*str);
	if (len - sign < scheme->precision)
	{
		if ((line = ft_strnew(scheme->precision + sign)))
		{
			if (sign)
				ft_strncpy(line, *str, sign);
			ft_memset(line + sign, '0', scheme->precision - len + sign);
			ft_strcpy(line + scheme->precision - len + sign * 2, *str + sign);
			free(*str);
			*str = line;
		}
	}
}

void			width_number(t_scheme *scheme, char **str)
{
	int		len;
	char	*line;
	int		sign;

	len = ft_strlen(*str);
	if (len < scheme->width)
	{
		if (!scheme->flag->zero)
			width_str(scheme, str);
		else if ((line = ft_strnew(scheme->width)))
		{
			sign = sign_control(*str);
			if (sign)
				ft_strncpy(line, *str, sign);
			ft_memset(line + sign, '0', scheme->width - len + sign);
			ft_strcpy(line + scheme->width - len + sign, *str + sign);
			free(*str);
			*str = line;
		}
	}
}

void			sign_number(t_flag *flag, char **str)
{
	char	*line;

	if (**str != '-')
	{
		if ((line = ft_strnew(ft_strlen(*str) + 1)))
		{
			*line = flag->plus ? '+' : ' ';
			ft_strcpy(line + 1, *str);
			free(*str);
			*str = line;
		}
	}
}

void			add_base(t_scheme *scheme, char **str)
{
	char		*format;
	char		*line;
	int			n;

	format = ft_strdup("0x");
	n = 0;
	if (scheme->type == 'p' || scheme->type == 'x' || scheme->type == 'X')
		n = 2;
	else if (scheme->type == 'o')
		n = 1;
	if ((line = ft_strnew(ft_strlen(*str) + n)))
	{
		if (scheme->type == 'X')
			ft_strcase(format, UP);
		ft_strncpy(line, format, n);
		ft_strcpy(line + n, *str);
		free(*str);
		*str = line;
	}
	free(format);
}