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
	intmax_t	number;

	if (scheme->size == 'l' || scheme->type == 'D')
		number = va_arg(ptr, long int);
	else if (scheme->size == 0)
		number = va_arg(ptr, int);
	else if (scheme->size == 'l' + 'l')
		number = va_arg(ptr, long long int);
	else if (scheme->size == 'h')
		number = va_arg(ptr, short);
	else if (scheme->size == 'h' + 'h')
		number = va_arg(ptr, signed char);
	else if (scheme->size == 'j')
		number = va_arg(ptr, intmax_t);
	else
		exit(1);
	return (f_itoa(number));
}

char	*create_ou(t_scheme *scheme, va_list ptr)
{
	intmax_t	number;
	int			base;

	if (scheme->type == 'o' || scheme->type == 'O')
		base = 8;
	else
		base = 10;
	if (scheme->size == 'l' || scheme->type == 'O' || scheme->type == 'U')
		number = va_arg(ptr, unsigned long int);
	else if (scheme->size == 0)
		number = va_arg(ptr, unsigned int);
	else if (scheme->size == 'l' + 'l')
		number = va_arg(ptr, unsigned long long int);
	else if (scheme->size == 'h')
		number = va_arg(ptr, unsigned short);
	else if (scheme->size == 'h' + 'h')
		number = va_arg(ptr, unsigned char);
	else if (scheme->size == 'j')
		number = va_arg(ptr, uintmax_t);
	else if (scheme->size == 'z')
		number = va_arg(ptr, size_t);
	return (ft_itoa_base(number, base));
}

char	*create_x(t_scheme *scheme, va_list ptr)
{
	intmax_t	number;
	char		*line;

	if (scheme->size == 'l')
		number = va_arg(ptr, unsigned long int);
	else if (scheme->size == 0)
		number = va_arg(ptr, unsigned int);
	else if (scheme->size == 'l' + 'l')
		number = va_arg(ptr, unsigned long long int);
	else if (scheme->size == 'h')
		number = va_arg(ptr, unsigned short);
	else if (scheme->size == 'h' + 'h')
		number = va_arg(ptr, unsigned char);
	else if (scheme->size == 'j')
		number = va_arg(ptr, uintmax_t);
	else if (scheme->size == 'z')
		number = va_arg(ptr, size_t);
	line = ft_itoa_base(number, 16);
	return (sheme->type == 'X' ? ft_toupper(line) : line);
}
