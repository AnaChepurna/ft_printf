/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:32:11 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/15 20:11:31 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_int_octal(va_list ptr)
{
	unsigned int	number;

	number = va_arg(ptr, unsigned int);
	printf ("number ---> %lu\n", number);
	return(ft_itoa_base(number, 10));
}
