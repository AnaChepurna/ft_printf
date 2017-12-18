/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:32:11 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/18 14:07:51 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_int_octal(va_list ptr)
{
	unsigned int	number;

	number = va_arg(ptr, unsigned int);
	return(ft_itoa_base(number, 8));
}
