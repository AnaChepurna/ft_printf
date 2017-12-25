/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creators.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 20:02:16 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 20:14:54 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_di(t_scheme *scheme, va_list ptr)
{
	intmax_t	number;

	if (scheme->size == 'l' || scheme->type == 'D')
		number = va_arg(ptr, long int);
	else if (scheme->size == 0)
		number = va_arg(ptr, int);
	else if (scheme->size == 'l' + 'l')
		number = va_arg(ptr, long long int);
	else if (scheme->size == 'h')
		number = va_arg(ptr, signed char);
	else if (scheme->size == 'h' + 'h')
		number = va_arg(ptr, short);
	return (f_itoa(number));
}
