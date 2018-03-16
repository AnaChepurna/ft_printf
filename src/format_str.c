/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:47:31 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/16 15:47:32 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		width_str(t_scheme *scheme, char **str)
{
	int		len;
	char	*line;

	len = ft_strlen(*str);
	if (len < scheme->width)
	{
		if ((line = ft_strnew(scheme->width)))
		{
			if (!(scheme->flag & F_MINUS))
			{
				ft_memset(line, ' ', scheme->width - len);
				ft_strcpy(line + scheme->width - len, *str);
			}
			else
			{
				ft_strcpy(line, *str);
				ft_memset(line + len, ' ', scheme->width - len);
			}
			free(*str);
			*str = line;
		}
	}
}

void		precision_str(t_scheme *scheme, char **str)
{
	char	*line;

	if (ft_strlen(*str) > scheme->precision)
	{
		if ((line = ft_strnew(scheme->precision)))
		{
			ft_strncpy(line, *str, scheme->precision);
			free(*str);
			*str = line;
		}
	}
}
