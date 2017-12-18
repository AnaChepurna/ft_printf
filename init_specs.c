/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_specs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:43:51 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/18 18:32:35 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_arg	*argnew(char *type, char *(*f)(va_list ptr))
{
	t_arg *res;

	if ((res = (t_arg *)malloc(sizeof(t_arg))))
	{
		res->type = type;
		res->f = f;
	}
	return (res);
}

t_arg			**init_specs(void)
{
	t_arg	**res;

	if ((res =(t_arg **)malloc(sizeof(t_arg *) * 3)))
	{i
		res[0] = argnew("d", &get_int_decimal);
		res[1] = argnew("o", &get_int_octal);
		res[2] = NULL;
	}
	return (res);
}
