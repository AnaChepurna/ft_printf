/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creators.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 20:02:16 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 17:34:08 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_di(t_scheme *scheme, va_list ptr)
{
	char	*str;

	str = ft_itoa(get_i(scheme, ptr));
	if ((scheme->flag & F_ZERO) && (scheme->width))
		scheme->flag -= F_ZERO;
	if ((scheme->flag & F_PLUS) || (scheme->flag & F_SPACE))
		sign_number(scheme, &str);
	if (scheme->precision > -1)
		precision_number(scheme, &str);
	if (scheme->width)
		width_number(scheme, &str);
	return (str);
}

char	*create_oux(t_scheme *scheme, va_list ptr)
{
	char	*str;
	int		base;

	if (IS_O(scheme->type))
		base = 8;
	else if (IS_X(scheme->type))
		base = 16;
	else
		base = 10;
	if ((scheme->flag & F_ZERO) && (scheme->precision > 0))
		scheme->flag = scheme->flag ^ F_ZERO;
	str = ft_itoa_base(get_u(scheme, ptr), base);
	if (scheme->flag & F_HASH)
		add_base(scheme, &str);
	if (scheme->precision > -1)
		precision_number(scheme, &str);
	if (scheme->width)
		width_number(scheme, &str);
	if (scheme->type == 'X')
		ft_strcase(str, UP);
	return (str);
}

char	*create_p(t_scheme *scheme, va_list ptr)
{
	char	*str;

	str = ft_itoa_base(get_u(scheme, ptr), 16);
	add_base(scheme, &str);
	if (scheme->width)
		width_str(scheme, &str);
	return (str);
}

char	*create_s(t_scheme *scheme, va_list ptr)
{
	char	*str;
	char	*s;
	char	c;

	if (scheme->type == 's')
	{
		s = get_s(scheme, ptr);
		str = s ? ft_strdup(s) : ft_strdup("(null)");
	}
	else
	{
		c = get_c(scheme, ptr);
		str = ft_strdup(&c);
	}
	if (scheme->precision > 0)
		precision_str(scheme, &str);
	if (scheme->width)
		width_str(scheme, &str);
	return (str);
}

char	*create_frm(t_scheme *scheme)
{
	char	*str;

	str = ft_strdup("%");
	if (scheme->width)
		width_str(scheme, &str);
	return (str);
}
