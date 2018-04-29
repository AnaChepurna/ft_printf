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

static void		create_format(int *symbols, t_scheme *scheme, va_list ptr)
{
	if (scheme->type == '%')
	 	scheme->str = ft_strdup("%");
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
	// else if (IS_E(scheme->type))
	// 	ft_putnbr((int)get_f(scheme, ptr));
	// else if (IS_B(scheme->type))
	// 	create_b(symbols, scheme, ptr);
	else if (scheme->type == 'n')
		create_n(symbols, ptr);
	else
		scheme->str = ft_strdup("n");
}

void			print_scheme(t_scheme *scheme)
{
	printf("flags = %i\n", scheme->flag);
	printf("width = %i\n", scheme->width);
	printf("preci = %i\n", scheme->precision);
	printf("size  = %c\n", (char)scheme->size);
	printf("type  = %c\n", (char)scheme->type);
	printf("order = %i\n", scheme->order);
}

static void		put_format(t_scheme *scheme)
{
	int	len;
	int	i;

	len = ft_strlen(scheme->str);
	if (scheme->precision > -1 && len > scheme->precision)
		len = scheme->precision;
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

// void			create_len(t_scheme *scheme)
// {
// 	if ((scheme->flag & SIGN) || (scheme->flag & F_PLUS) || scheme->flag & F_SPACE)
// 		scheme->len++;

// }

void			print_format(int *symbols, t_scheme *scheme)
{
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
	if (scheme->type == 'p' || !ft_strequ(scheme->str, "0"))
	{
		if (scheme->flag & ALT1)
			ft_putstr("0");
		if (scheme->flag & ALT2 && scheme->type == 'X')
			ft_putstr("X");
		else if (scheme->flag & ALT2)
			ft_putstr("x");
	}
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
	symbols += scheme->len;
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
	//print_scheme(scheme);
	create_format(symbols, scheme, ptr);
	if (scheme->type != 'n')
		print_format(symbols, scheme);
	scheme_del(&scheme);
	return (i);
}
