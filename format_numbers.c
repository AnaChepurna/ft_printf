/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:54:16 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 18:18:14 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_number(int precision, char **str)
{
	int		len;
	char	*line;
	int		i;

	len = (int)ft_strlen(*str);
	printf("len = %i, pr =  %i\n", len, precision);
	if (len < precision)
	{
		if ((line = ft_strnew(precision)))
		{
			i = 0;
			while (len + i < precision)
			{
				line[i] = '0';
				i++;
			}
			printf("0s added\n");
			ft_strcpy(line + i, *str);
		}
		free(*str);
		*str = line;
	}
}

void		width_number(t_scheme *scheme, char **str)
{
	int		len;
	char	*line;
	int		sign;

	len = ft_strlen(*str);
	if (len < scheme->width)
	{
		printf("%i\n", scheme->flag->zero);
		if (!scheme->flag->zero)
			width_str(scheme, str);
		else if ((line = ft_strnew(scheme->width)))
		{
			sign = 0;
			if (**str == '-' || **str == '+' || **str == ' ')
			{
				*line = **str;
				sign = 1;
			}
			ft_memset(line + sign, '0', scheme->width - len + 1);
			ft_strcpy(line + scheme->width - len + 1, *str + sign);
			free(*str);
			*str = line;
		}
	}
}

void		sign_number(t_flag *flag, char **str)
{
	char	*line;

	if (**str != '-')
	{
		if ((line = ft_strnew(ft_strlen(*str) + 1)))
		{
			*line = flag->plus ? '+' : ' ';
			ft_strcpy(line + 1, *str);
			free(*str);
			*str = line;
		}
	}
}