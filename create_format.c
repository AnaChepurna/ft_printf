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
	printf("create_str\n");
	if (IS_DI(scheme->type))
		return (create_di(scheme, ptr));
	if (IS_O(scheme->type) || IS_X(scheme->type) || IS_U(scheme->type))
		return (create_oux(scheme, ptr));
//////////////////
	printf("NULL\n");
	return (NULL);
}

char		*create_format(t_scheme *scheme, va_list ptr)
{
	char *res;

	printf("create_format\n");
	res = create_str(scheme, ptr);
	return (res);
}
