/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:52:04 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/03 13:52:07 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_format(t_scheme *scheme)
{
	int	len;
	int	i;

	len = ft_strlen(scheme->str);
	if (scheme->precision > -1 && len > scheme->precision)
		len = scheme->precision;
	if ((IS_C(scheme->type)) && !len)
		len = 1;
	i = 0;
	while (i < len)
	{
		if (len < scheme->precision)
		{
			(scheme->precision)--;
			ft_putchar('0');
		}
		else
			ft_putchar(scheme->str[i++]);
	}
}

static void		put_width(t_scheme *scheme)
{
	while (scheme->width > scheme->len && scheme->flag & F_ZERO)
	{
		ft_putstr("0");
		(scheme->len)++;
	}
	put_format(scheme);
	while (scheme->width > scheme->len)
	{
		ft_putstr(" ");
		(scheme->len)++;
	}
}

static void		stabilize_len(t_scheme *scheme)
{
	int		len;

	if (scheme->precision > -1 && (len = ft_strlen(scheme->str)) >
		scheme->precision)
		scheme->len -= len - scheme->precision;
}

void			print_format(int *symbols, t_scheme *scheme)
{
	stabilize_len(scheme);
	while (scheme->width > scheme->len && !(scheme->flag & F_ZERO)
		&& !(scheme->flag & F_MINUS))
	{
		(scheme->len)++;
		ft_putstr(" ");
	}
	if (scheme->flag & SIGN)
		ft_putstr("-");
	else if (scheme->flag & F_SPACE)
		ft_putstr(" ");
	else if (scheme->flag & F_PLUS)
		ft_putstr("+");
	if (scheme->type == 'p' || !ft_strequ(scheme->str, "0") ||
		IS_O(scheme->type))
	{
		if (scheme->flag & ALT1)
			ft_putstr("0");
		if (scheme->type == 'A' || (scheme->flag & ALT2 && scheme->type == 'X'))
			ft_putstr("X");
		else if (scheme->flag & ALT2)
			ft_putstr("x");
	}
	put_width(scheme);
	*symbols += scheme->len;
}
