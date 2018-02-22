/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheme_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:47:54 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 18:19:11 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag		*flag_new(void)
{
	t_flag	*res;

	if ((res = (t_flag *)malloc(sizeof(t_flag))))
	{
		res->minus = 0;
		res->plus = 0;
		res->space = 0;
		res->hash = 0;
		res->zero = 0;
	}
	return (res);
}

t_scheme			*scheme_new(void)
{
	t_scheme	*res;

	if ((res = (t_scheme *)malloc(sizeof(t_scheme))))
	{
		res->flag = flag_new();
		res->width = 0;
		res->precision = 0;
		res->size = 0;
		res->type = 0;
	}
	return (res);
}

void				scheme_del(t_scheme **s)
{
	free((*s)->flag);
	free(*s);
	*s = NULL;
}

void		print_scheme(t_scheme *s)
{
	printf("--SCHEME:\nflags => minus %i, plus %i, space %i, hash %i, zero %i\n width %i\n precision = %i\n size %i\n type %i\n--\n", 
		s->flag->minus, s->flag->plus, s->flag->space,
		s->flag->hash, s->flag->zero, s->width, s->precision,
		s->size, s->type);
}
