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

void	handle_line(const char **format, t_list **list)
{
	char	*start;
	char	*str;
	size_t	len;

	start = *format;
	while (**format && **format != '%')
		(*format)++;
	str = NULL;
	len = *format - start;
	if (len)
	{
		str = ft_strsub(start, 0, len);
		ft_lstaddend(list, ft_lstnew(str, len));
		free(str);
	}
}
