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
		if (*str == '0' && !(*(str + 1)))
			sign--;
	}
	return (sign);
}

void			precision_number(t_scheme *scheme, char **str)
{
	int		len;
	char	*line;
	int		sign;

	if (!scheme->precision)
		precision_str(scheme, str);
	sign = sign_control(*str);
	len = (int)ft_strlen(*str);
	if (len - sign < scheme->precision)
	{
		printf("%i\n", scheme->precision);
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
		//printf("%i\n", scheme->flag);
		if (!(scheme->flag & F_ZERO) || scheme->flag & F_MINUS)
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

void			sign_number(t_scheme *scheme, char **str)
{
	char	*line;

	if (**str != '-')
	{
		if ((line = ft_strnew(ft_strlen(*str) + 1)))
		{
			*line = scheme->flag & F_PLUS ? '+' : ' ';
			ft_strcpy(line + 1, *str);
			free(*str);
			*str = line;
		}
	}
}

void			add_base(t_scheme *scheme, char **str)
{
	const char	*format = "0x";
	char		*line;
	int			n;

	if (ft_strequ(*str, "0"))
		return ;
	n = 0;
	if (scheme->type == 'p' || IS_X(scheme->type))
		n = 2;
	else if (IS_O(scheme->type))
		n = 1;
	if ((line = ft_strnew(ft_strlen(*str) + n)))
	{
		ft_strncpy(line, format, n);
		ft_strcpy(line + n, *str);
		free(*str);
		*str = line;
	}
}