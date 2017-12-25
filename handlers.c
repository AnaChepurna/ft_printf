/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bt: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:24:01 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 19:59:03 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flags(const char *format, t_flag *flag)
{
	if (*format == '-')
		return (flag->minus = 1);
	if (*format == '+')
		return (flag->plus = 1);
	if (*format == ' ')
		return (flag->spase = 1);
	if (*format == '#')
		return (flag->hash = 1);
	if (*format == '0')
		return (flag->zero = 1);
	return (0);
}

void	handle_precision(const char **format, t_scheme *scheme)
{
	if (**format == '.')
	{
		(*format)++;
		scheme->precision = ft_atoi(*format);
		while (IS_NUMBER(**format))
			(*format)++;
	}
}

void	handle_width(const char **format, t_scheme *scheme, va_list ptr)
{
	if (**format == '*')
	{
		scheme->width = va_arg(ptr, size_t);
		(*format)++;
	}
	else
	{
		scheme->width = ft_atoi(*format);
		while (IS_NUBMER(**format))
			(*format)++;
	}
}

void	handle_size(const char **format, t_scheme *scheme)
{
	if (ft_strnequ(*format, "h", 1))
		scheme->size = 'h';
	else if (ft_strnequ(*format, "hh", 2))
	{
		scheme->size = 'h' + 'h';
		(*format)++;
	}
	else if (ft_strnequ(*format, "l", 1))
		scheme->size = 'l';
	else if (ft_strnequ(*format, "ll", 2))
	{
		scheme->size = 'l' + 'l';
		(*format)++;
	}
	else if (ft_strnequ(*format, "j", 1))
		scheme->size = 'j';
	else if (ft_strnequ(*format, "z", 1))
		scheme->size = 'z';
	(*format)++;
}

void	handle_type(const char **format, t_scheme *scheme)
{	
	scheme->type = **format;
	(*format)++;
}
