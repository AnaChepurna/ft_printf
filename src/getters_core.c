/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:29:04 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/20 11:27:54 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_i(t_scheme *scheme, va_list ptr)
{
	intmax_t	number;

	if (scheme->size == 'l' || scheme->type == 'D')
		number = va_arg(ptr, long int);
	else if (scheme->size == 0)
		number = va_arg(ptr, int);
	else if (scheme->size == 'h')
		number = (short)va_arg(ptr, int);
	else if (scheme->size == 'h' + 'h')
		number = (signed char)va_arg(ptr, int);
	else if (scheme->size == 'l' + 'l')
		number = va_arg(ptr, long long int);
	else if (scheme->size == 'j')
		number = va_arg(ptr, intmax_t);
	else if (scheme->size == 'z')
		number = va_arg(ptr, ssize_t);
	else
		exit(1);
	if (number < 0)
	{
		number = -number;
		scheme->flag += SIGN;
	}
	return (number);
}

uintmax_t	get_u(t_scheme *scheme, va_list ptr)
{
	uintmax_t	number;

	if (scheme->size == 'l' || scheme->type == 'O' ||
		scheme->type == 'U' || scheme->type == 'p')
		number = va_arg(ptr, unsigned long int);
	else if (scheme->size == 0)
		number = va_arg(ptr, unsigned int);
	else if (scheme->size == 'l' + 'l')
		number = va_arg(ptr, unsigned long long int);
	else if (scheme->size == 'h')
		number = (unsigned short)va_arg(ptr, unsigned int);
	else if (scheme->size == 'h' + 'h')
		number = (unsigned char)va_arg(ptr, unsigned int);
	else if (scheme->size == 'z')
		number = va_arg(ptr, size_t);
	else if (scheme->size == 'j')
		number = va_arg(ptr, uintmax_t);
	else
		exit(1);
	return (number);
}

wchar_t		get_c(t_scheme *scheme, va_list ptr)
{
	wchar_t		symbol;

	if (scheme->size == 'l' || scheme->type == 'C')
		symbol = (wchar_t)va_arg(ptr, wint_t);
	else
		symbol = (unsigned char)va_arg(ptr, int);
	return (symbol);
}

void		*get_s(t_scheme *scheme, va_list ptr)
{
	void	*pointer;

	if (scheme->type == 'S' || scheme->size == 'l')
		pointer = va_arg(ptr, wchar_t *);
	else
		pointer = va_arg(ptr, char *);
	return (pointer);
}
