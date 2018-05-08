/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:21:23 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 18:21:59 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flags(const char *format, t_scheme *scheme)
{
	if (*format == '-')
		return (scheme->flag = scheme->flag | F_MINUS);
	if (*format == '+')
		return (scheme->flag = scheme->flag | F_PLUS);
	if (*format == ' ')
		return (scheme->flag = scheme->flag | F_SPACE);
	if (*format == '#')
		return (scheme->flag = scheme->flag | F_HASH);
	if (*format == '0')
		return (scheme->flag = scheme->flag | F_ZERO);
	return (0);
}

int		handle_precision(const char *format, t_scheme *scheme, va_list ptr)
{
	int		i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			scheme->precision = va_arg(ptr, size_t);
			i++;
		}
		else
		{
			scheme->precision = ft_atoi(format + i);
			while (IS_NUMBER(format[i]))
				i++;
		}
	}
	return (i);
}

int		handle_width(const char *format, t_scheme *scheme, va_list ptr)
{
	int		i;

	i = 0;
	if (format[i] == '*')
	{
		scheme->width = va_arg(ptr, size_t);
		if (scheme->width < 0)
			scheme->width = 0;
		i++;
	}
	else
	{
		scheme->width = ft_atoi(format);
		while (IS_NUMBER(format[i]))
			i++;
	}
	if (format[i] == '$')
	{
		scheme->order = scheme->width;
		scheme->width = 0;
		i++;
	}
	return (i);
}

int		handle_size(const char *format, t_scheme *scheme)
{
	int		i;

	i = 0;
	if (ft_strnequ(format, "hh", 2))
	{
		scheme->size = 'h' + 'h';
		i++;
	}
	else if (ft_strnequ(format, "h", 1))
		scheme->size = 'h';
	else if (ft_strnequ(format, "ll", 2))
	{
		scheme->size = 'l' + 'l';
		i++;
	}
	else if (ft_strnequ(format, "l", 1))
		scheme->size = 'l';
	else if (ft_strnequ(format, "j", 1))
		scheme->size = 'j';
	else if (ft_strnequ(format, "z", 1))
		scheme->size = 'z';
	else if (ft_strnequ(format, "L", 1))
		scheme->size = 'L';
	return (scheme->size ? ++i : i);
}

int		handle_type(const char *format, t_scheme *scheme)
{
	scheme->type = *format;
	return (1);
}
