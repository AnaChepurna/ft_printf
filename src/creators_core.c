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

void	create_di(t_scheme *scheme, va_list ptr)
{
	char		*str;
	intmax_t	number;
	int			len;

	number = get_i(scheme, ptr);
	str = ft_itoa(number);
	scheme->str = str;
	len = ft_strlen(scheme->str);
	if (len > scheme->precision && number)
		scheme->precision = -1;
	if (ft_strequ(scheme->str, "-9223372036854775808"))
		scheme->flag -= SIGN;
	len = scheme->precision <= len ? len : scheme->precision;
	if ((scheme->flag & SIGN) || (scheme->flag & F_PLUS) ||
		(scheme->flag & F_SPACE))
		len++;
	scheme->len = len;
}

void	create_oux(t_scheme *scheme, va_list ptr)
{
	int			base;
	uintmax_t	number;

	base = 8;
	if (!(IS_O(scheme->type)))
		base = (IS_X(scheme->type)) ? 16 : 10;
	if ((scheme->flag & F_ZERO) && (scheme->precision > -1))
		scheme->flag = scheme->flag ^ F_ZERO;
	number = get_u(scheme, ptr);
	scheme->str = ft_itoa_base(number, base);
	if (scheme->type == 'X')
		ft_strcase(scheme->str, UP);
	scheme->len = ft_strlen(scheme->str);
	scheme->len = scheme->precision <= scheme->len ?
	scheme->len : scheme->precision;
	stabilize_oux(scheme, number);
}

void	create_p(t_scheme *scheme, va_list ptr)
{
	char	*str;

	str = ft_itoa_base(get_u(scheme, ptr), 16);
	scheme->str = str;
	scheme->len = ft_strlen(str) + 2;
	scheme->flag += ALT1;
	scheme->flag += ALT2;
}

void	create_s(t_scheme *scheme, va_list ptr)
{
	void	*s;

	s = get_s(scheme, ptr);
	if (!s && scheme->precision < 6 && scheme->precision > -1)
		scheme->str = ft_strdup("");
	else if (!s)
		scheme->str = ft_strdup("(null)");
	else if (scheme->type == 'S' || scheme->size == 'l')
	{
		// if (MB_CUR_MAX != LC_ALL)
		// 	return ;
		scheme->str = get_strunicode(s);
		if (scheme->precision > -1 && scheme->precision < ft_strlen(scheme->str))
		{
			while (scheme->str[scheme->precision - 1] < 0 &&
				scheme->str[scheme->precision - 1] > -63)
				scheme->precision--;
		}
	}
	else
		scheme->str = ft_strdup((char *)s);
	scheme->len = ft_strlen(scheme->str);
}

void	create_c(t_scheme *scheme, va_list ptr)
{
	wchar_t	c;

	c = get_c(scheme, ptr);
	if (scheme->type == 'C' || scheme->size == 'l')
	{
		// if (MB_CUR_MAX != LC_ALL)
		// 	return ;
		scheme->str = get_unicode(c);
	}
	else
	{
		if ((scheme->str = ft_strnew(1)))
			(scheme->str)[0] = (char)c;
	}
	scheme->len = ft_strlen(scheme->str);
	if (!c)
		scheme->len = 1;
}
