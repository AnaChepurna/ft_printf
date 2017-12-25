/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:29:19 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 19:42:16 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *restrict format, ...)
{
	t_list			*list;
	va_list			ptr;

	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
			handle_format(&(format + 1), &list, ptr);
		else
			handle_line(&format, &line);
	}
	va_end(ptr);
	ft_lstiter(list, &ft_putstr);
}
