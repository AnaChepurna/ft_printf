/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_adds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:47:16 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/16 15:49:41 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		get_f(t_scheme *scheme, va_list ptr)
{
	long double	number;

	if (scheme->type == 'D' || scheme->size == 'L')
		number = va_arg(ptr, long double);
	else
		number = va_arg(ptr, double);
	if (scheme->precision == -1 && !(IS_A(scheme->type)))
		scheme->precision = 6;
	if (scheme->precision == -1 && (IS_A(scheme->type)))
		scheme->precision = 14;
	return (number);
}
