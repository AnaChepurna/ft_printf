/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:23:09 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 20:15:12 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_str(t_scheme *scheme, va_list ptr)
{
	if (IS_DI(scheme->type))
		return (create_di(scheme, ptr));
	if (IS_OX(scheme->type) || IS_U(scheme->type))
		return (create_oxu(scheme, ptr));
}

char		*create_format(t_scheme *scheme, va_list ptr)
{
	char *res;

	res = create_str(scheme, va_list ptr);
}
