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