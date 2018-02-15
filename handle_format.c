/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:14:52 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 17:13:11 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_format(const char *format, t_list **list, va_list ptr)
{
	t_scheme	*scheme;
	char		*str;
	int			i;

	i = 0;
	printf("handle_format\n");
	if (format[i] == '%')
		str = ft_strdup("%");
	else
	{
		scheme = scheme_new();
		while (handle_flags(format + i, scheme->flag))
			i++;
		i += handle_width(format + i, scheme, ptr);
		i += handle_precision(format + i, scheme, ptr);
		i += handle_size(format + i, scheme);
		i += handle_type(format + i, scheme);
		print_scheme(scheme);
		str = create_format(scheme, ptr);
	}
	ft_lstaddend(list, ft_lstnew(str, ft_strlen(str) + 1));
	printf("----just added %s to the list\n", str);
	free(str);
	scheme_del(&scheme);
	return (i);
}
