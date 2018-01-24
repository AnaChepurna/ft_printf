/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:23:09 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 18:18:12 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_str(t_scheme *scheme, va_list ptr)
{
	if (IS_DI(scheme->type))
		return (create_di(scheme, ptr));
	if (IS_OU(scheme->type))
		return (create_ou(scheme, ptr));
	if (IS_X(scheme->type))
		return (create_x(scheme, ptr));
}

static char	*create_format(t_scheme *scheme, char **str)
{
	if (scheme->precision)
	{
		if (IS_DI(scheme->type) || IS_OU(scheme->type) || IS_X(scheme))
			precision_number(scheme->precision, str);
	}
	if
}

char		*create_format(t_scheme *scheme, va_list ptr)
{
	char *res;

	res = create_str(scheme, va_list ptr);
	res = create_format(scheme, &res);
}
