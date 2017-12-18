/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:54:16 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/18 15:54:16 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_int_decimal(va_list ptr)
{
	int		number;

	number = va_arg(ptr, int);
	return (ft_itoa(number));
}

char	*get_llint_decimal(va_list ptr)
{
	long long int number;

	number = va_arg(ptr, long long int);
	return (ft_itoa(number));
}

char	*get_lint_decimal(va_list ptr)
{
	long int		number;

	number = va_arg(ptr, long int);
	return (ft_itoa(number));
}

char	*get_intmax_t_decimal(va_list ptr)
{
	intmax_t		number;

	number = va_arg(ptr, intmax_t);
	return (ft_itoa(number));
}

char	*get_size_t_decimal(va_list ptr)
{
	size_t		number;

	number = va_arg(ptr, size_t);
	return (ft_itoa(number));
}
