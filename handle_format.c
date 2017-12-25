/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:14:52 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 15:03:51 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flags(const char *format, t_flag *flag)
{
	if (**format == '-')
		return (flag->minus = 1);
	if (**format == '+')
		return (flag->plus = 1);
	if (**format == ' ')
		return (flag->spase = 1);
	if (**format == '#')
		return (flag->hash = 1);
	if (**format == '0')
		return (flag->zero = 1);
	return (0);
}

void	handle_format(const char **format, t_list **list)
{
	t_scheme	*scheme;

	scheme = scheme_new();
	while (handle_flags(*format, scheme->flag))
		(*format)++;
}
