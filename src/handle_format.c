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

static void		create_frm(int *symbols, t_scheme *scheme)
{
	char	*str;

	str = ft_strdup("%");
	if (scheme->width)
		width_str(scheme, &str);
	ft_putstr(str);
	*symbols += ft_strlen(str);
	free(str);
}

static void		create_format(int *symbols, t_scheme *scheme, va_list ptr)
{
	// if (scheme->type == '%')
	// 	create_frm(symbols, scheme);
	if (IS_I(scheme->type))
		create_di(symbols, scheme, ptr);
	// else if (IS_O(scheme->type) || IS_X(scheme->type) || IS_U(scheme->type))
	// 	create_oux(symbols, scheme, ptr);
	// else if (scheme->type == 'p')
	// 	create_p(symbols, scheme, ptr);
	// else if (IS_S(scheme->type))
	// 	(create_s(symbols, scheme, ptr));
	// else if (IS_C(scheme->type))
	// 	create_c(symbols, scheme, ptr);
	// else if (IS_F(scheme->type) || IS_E(scheme->type) || IS_A(scheme->type))
	// 	create_fe(symbols, scheme, ptr);
	// else if (IS_B(scheme->type))
	// 	create_b(symbols, scheme, ptr);
	// else if (scheme->type == 'n')
	// 	create_n(symbols, ptr);
	else
		ft_putstr("nope");
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
	scheme_del(&scheme);
	return (i);
}
