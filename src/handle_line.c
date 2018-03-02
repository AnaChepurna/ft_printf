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

int		handle_line(const char *format, t_list **list)
{
	int		i;
	char	*str;

	//printf("handle_line\n");
	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	str = NULL;
	//printf("%i signs of simple line\n", i);
	if (i)
	{
		str = ft_strsub(format, 0, i);
		//printf("str created\n");
		ft_lstaddend(list, ft_lstnew(str, i + 1));
		//printf("----just added %s to the list\n", str);
		free(str);
	}
	return (i);
}
