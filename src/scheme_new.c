/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheme_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:47:54 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/16 15:29:20 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_scheme			*scheme_new(void)
{
	t_scheme	*res;

	if ((res = (t_scheme *)malloc(sizeof(t_scheme))))
	{
		res->flag = 0;
		res->width = 0;
		res->precision = -1;
		res->size = 0;
		res->type = 0;
		res->order = 0;
		res->str = NULL;
	}
	return (res);
}

void				scheme_del(t_scheme **s)
{
	if ((*s)->str)
		free((*s)->str);
	free(*s);
	*s = NULL;
}
