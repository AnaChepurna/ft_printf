/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:29:19 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/18 18:54:43 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *restrict format, ...)
{
	static t_arg	**specs = NULL;
	char			*line;
	t_list			*list;

	if (!specs)
		specs = init_specs();
	line = format;
	res = NULL;
	while (*format)
	{
		if(*format = '%')
		{
			if (format != line)
				handle_line(line, format, &list);
			format += handle_specs(&list);
			line = format;
		}
		if (*format)
			format++;
	}
	ft_lstiteri(list, &ft_putstr);
}
