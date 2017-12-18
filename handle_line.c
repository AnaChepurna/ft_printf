/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:13:11 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/18 18:51:36 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_line(char *line, const char *format, t_list **list)
{
	char	*res;

	if (res = ft_strnew(format - line))
	{
		ft_strncpy(res, line, format - line);
	}
	ft_lstaddend(list, ft_lstnew((void *)res, format - line + 1));
	free(res);
}
