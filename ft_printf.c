/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:29:19 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 16:50:33 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *restrict format, ...)
{
	t_list			*list;

	while (*format)
	{
		if (*format == '%')
			handle_format(&format, &list);
		else
			handle_line(&format, &line);
	}
	ft_lstiter(list, &ft_putstr);
}
