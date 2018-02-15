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
	if (IS_OU(scheme->type))
		return (create_ou(scheme, ptr));
	if (IS_X(scheme->type))
		return (create_x(scheme, ptr));
//////////////////
	printf("NULL\n");
	return (NULL);
}

static char	*format_number(t_scheme *scheme, char **str)
{
	if (scheme->flag->plus || scheme->flag->space)
		sign_number(scheme->flag, str);
	if (scheme->flag->hash)
		add_base(scheme, str);
	if (scheme->precision)
		precision_number(scheme, str);
	if (scheme->width)
		width_number(scheme, str);
	return (*str);
}

static char	*formating(t_scheme *scheme, char **str)
{
	printf("formating\n");
	if (IS_DI(scheme->type) ||
		IS_OU(scheme->type) || IS_X(scheme->type))
		format_number(scheme, str);
	return (*str);
}

char		*create_format(t_scheme *scheme, va_list ptr)
{
	char *res;

	printf("create_format\n");
	res = create_str(scheme, ptr);
	res = formating(scheme, &res);
	return (res);
}
