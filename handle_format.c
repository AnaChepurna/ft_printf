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

void	handle_format(const char **format, t_list **list, va_list ptr)
{
	t_scheme	*scheme;
	char		*str;

	if (**format == '%')
		*str = ft_strdup("%");
	else
	{
		scheme = scheme_new();
		while (handle_flags(*format, scheme->flag))
			(*format)++;
		handle_width(format, ptr);
		handle_precision(format, scheme);
		handle_type(format, scheme);
		str = create_format(scheme, ptr);

		free(str);
		free(scheme->flag);
		free(scheme);
}
