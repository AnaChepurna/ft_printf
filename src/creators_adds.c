/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creators_adds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:47:46 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/16 15:47:48 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adder(t_scheme *scheme)
{
	if ((scheme->flag & SIGN) || (scheme->flag & F_PLUS) ||
		(scheme->flag & F_SPACE))
		scheme->len++;
}

void		create_fe(t_scheme *scheme, va_list ptr)
{
	char		*str;
	long double	number;

	number = get_f(scheme, ptr);
	if (!(str = handle_naninf(number)))
	{
		if (IS_F(scheme->type))
			str = create_float(scheme, number);
		else if (IS_E(scheme->type))
			str = create_exponent(scheme, number);
		else if (IS_A(scheme->type))
		{
			str = create_hexfloat(scheme, number);
			if (scheme->type == 'A')
				ft_strcase(str, UP);
			scheme->flag += ALT1 + ALT2;
		}
	}
	scheme->str = str;
	scheme->precision = -1;
	scheme->len = ft_strlen(str);
	adder(scheme);
}

void		create_g(t_scheme *scheme, va_list ptr)
{
	long double number;
	long double num;

	number = get_f(scheme, ptr);
	if (!(scheme->str = handle_naninf(number)))
	{
		num = number;
		num = find_expo(&num);
		if (number - (intmax_t)number == 0 && num < scheme->precision)
			scheme->str = ft_itoa(number);
		else
		{
			scheme->precision -= 3;
			if (num >= scheme->precision || num < -4)
				scheme->str = create_exponent(scheme, number);
			else
			{
				scheme->precision += 2 - (int)num;
				scheme->str = create_float(scheme, number);
			}
		}
	}
	scheme->len = ft_strlen(scheme->str);
	scheme->precision = -1;
	adder(scheme);
}

void		create_blanc(t_scheme *scheme)
{
	scheme->precision = -1;
	if (scheme->flag & F_SPACE)
		scheme->flag -= F_SPACE;
	scheme->str = ft_strdup("%");
	scheme->len = ft_strlen(scheme->str);
}

void		create_n(int *symbols, va_list ptr)
{
	int		*n;

	n = get_n(ptr);
	*n = *symbols;
}
