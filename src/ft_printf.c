/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:29:19 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 16:29:46 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_list(t_list *lst, int	*symbols)
{
	while (lst)
	{
		ft_putstr(BLUE);
		ft_putstr((char *)lst->content);
		*symbols += lst->content_size - 1;
		lst = lst->next;
		ft_putstr(RESET);
	}
}	

int				ft_printf(const char *restrict format, ...)
{
	t_list			*list;
	va_list			ptr;
	int				symbols;
	int				i;

	va_start(ptr, format);
	i = 0;
	list = NULL;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i += handle_format(format + i, &list, ptr);
		}
		else
			i += handle_line(format + i, &list);
	}
	va_end(ptr);
	//printf("end of handling\n");
	symbols = 0;
	print_list(list, &symbols);
	ft_lstdel(&list, &ft_memclr);
	return (symbols);
}
