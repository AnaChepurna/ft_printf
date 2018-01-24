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

void	precision_number(int precision, char **str)
{
	size_t	len;
	char	*line;
	int		i;

	len = strlen(*str);
	if (len < precision)
	{
		if ((line = ft_strnew(precision)))
		{
			i = 0;
			while (len < precision)
			{
				line[i] = '0';
				i++;
			}
			ft_strcpy(line + i, *str);
			free(*str);
			*str = line;
		}
	}
}
