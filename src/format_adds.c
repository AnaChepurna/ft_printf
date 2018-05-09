/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_adds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:19:51 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/09 16:19:53 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_naninf(long double number)
{
	if (number == INFINITY)
		return (ft_strdup("inf"));
	if (number == -INFINITY)
		return (ft_strdup("-inf"));
	if (isnan(number))
		return (ft_strdup("nan"));
	return (NULL);
}

void	stabilize_oux(t_scheme *scheme, uintmax_t number)
{
	if (!scheme->precision && !number && (IS_O(scheme->type)) &&
		scheme->flag & F_HASH)
		scheme->precision = 1;
	else if (scheme->len > scheme->precision && number)
		scheme->precision = -1;
	if (scheme->flag & F_HASH && (IS_O(scheme->type)) && number)
	{
		scheme->flag += ALT1;
		scheme->len++;
	}
	else if (scheme->flag & F_HASH && (IS_X(scheme->type)) && number)
	{
		scheme->flag += ALT1 + ALT2;
		scheme->len += 2;
	}
	if (scheme->flag & F_HASH && (IS_O(scheme->type)) &&
		scheme->precision > -1 && number)
	{
		scheme->len--;
		scheme->precision--;
	}
}
