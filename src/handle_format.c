/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:14:52 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/16 15:45:15 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stabilize(t_scheme *scheme)
{
	//print_scheme(scheme);
	if (scheme->flag & F_ZERO && scheme->precision > 0 &&
		scheme->type != '%') //&& !(IS_I(scheme->type) && scheme->type != 'p'))
		scheme->flag -= F_ZERO;
	if (scheme->flag & F_ZERO && scheme->flag & F_MINUS)
		scheme->flag -= F_ZERO;
	if (scheme->flag & F_SPACE && scheme->flag & F_PLUS)
		scheme->flag -= F_SPACE;
	if (IS_C(scheme->type) || !scheme->type)
	{
		scheme->precision = -1;
		if (scheme->flag & F_SPACE)
			scheme->flag -= F_SPACE;
		if (scheme->flag & F_PLUS)
			scheme->flag -= F_PLUS;
	}
	else if (IS_U(scheme->type) || IS_O(scheme->type) || IS_S(scheme->type) ||
		scheme->type == 'p' || IS_X(scheme->type))
	{
		if (scheme->flag & F_SPACE)
			scheme->flag -= F_SPACE;
		if (scheme->flag & F_PLUS)
			scheme->flag -= F_PLUS;
	}
	//print_scheme(scheme);
}

static void		no_spec(t_scheme *scheme)
{
	if ((scheme->str = ft_strnew(1)))
		(scheme->str)[0] = scheme->type;
	scheme->type = '\0';
	scheme->len = 1;
	//scheme->flag = 0;
}

static void		create_format(int *symbols, t_scheme *scheme, va_list ptr)
{
	if (scheme->type == '%')
		create_blanc(scheme);
	else if (IS_I(scheme->type))
		create_di(scheme, ptr);
	else if (IS_O(scheme->type) || IS_X(scheme->type) || IS_U(scheme->type))
		create_oux(scheme, ptr);
	else if (scheme->type == 'p')
		create_p(scheme, ptr);
	else if (IS_S(scheme->type))
		(create_s(scheme, ptr));
	else if (IS_C(scheme->type))
		create_c(scheme, ptr);
	else if (IS_F(scheme->type) || IS_E(scheme->type) || IS_A(scheme->type))
		create_fe(scheme, ptr);
	else if (IS_G(scheme->type))
		create_g(scheme, ptr);
	else if (scheme->type == 'n')
		create_n(symbols, ptr);
	else
		no_spec(scheme);
}

int				handle_format(const char *format, int *symbols, va_list ptr)
{
	t_scheme	*scheme;
	int			i;

	i = 0;
	scheme = scheme_new();
	while (handle_flags(format + i, scheme))
		i++;
	i += handle_width(format + i, scheme, ptr);
	if (scheme->order)
	{
		while (handle_flags(format + i, scheme))
			i++;
		i += handle_width(format + i, scheme, ptr);
	}
	i += handle_precision(format + i, scheme, ptr);
	i += handle_size(format + i, scheme);
	i += handle_type(format + i, scheme);
	create_format(symbols, scheme, ptr);
	stabilize(scheme);
	if (!(scheme->str))
		*symbols = -1;
	else if (scheme->type != 'n')
		print_format(symbols, scheme);
	// if (!(scheme->type))
	// 	i--;
	scheme_del(&scheme);
	return (i);
}
