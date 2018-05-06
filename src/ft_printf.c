/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:29:19 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 16:29:46 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *restrict format, ...)
{
	va_list			ptr;
	int				symbols;
	int				i;

	va_start(ptr, format);
	i = 0;
	symbols = 0;
	while (format[i] && symbols > -1)
	{
		if (symbols < 0)
			break ;
		if (format[i] == '%')
		{
			i++;
			i += handle_format(format + i, &symbols, ptr);
		}
		else
			i += handle_line(format + i, &symbols);
	}
	va_end(ptr);
	return (symbols);
}
