/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:13:11 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 15:03:31 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_line(const char *format, int *symbols)
{
	int		i;
	char	*str;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	str = NULL;
	if (i && *format)
	{
		str = ft_strsub(format, 0, i);
		ft_putstr(str);
		*symbols += i;
		free(str);
	}
	if (*format)
		return (i);
	else
		return (0);
}
