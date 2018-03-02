/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:14:52 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 17:13:11 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_format(t_scheme *scheme, va_list ptr)
{
	printf("create_str\n");
	if (IS_DI(scheme->type))
		return (create_di(scheme, ptr));
	if (IS_O(scheme->type) || IS_X(scheme->type) || IS_U(scheme->type))
		return (create_oux(scheme, ptr));
	if (scheme->type == 'p')
		return (create_p(scheme, ptr));
	if (IS_S(scheme->type))
		return (create_s(scheme, ptr));
	if (IS_F(scheme->type) || IS_E(scheme->type) || IS_A(scheme->type))
		return (create_fe(scheme, ptr));
	if (IS_B(scheme->type))
		return(create_b(scheme, ptr));
//////////////////
	printf("NULL\n");
	return (NULL);
}

int		handle_format(const char *format, t_list **list, va_list ptr)
{
	t_scheme	*scheme;
	char		*str;
	int			i;

	i = 0;
	printf("handle_format\n");
	if (format[i] == '%')
		str = ft_strdup("%");
	else
	{
		scheme = scheme_new();
		while (handle_flags(format + i, scheme))
			i++;
		i += handle_width(format + i, scheme, ptr);
		i += handle_precision(format + i, scheme, ptr);
		i += handle_size(format + i, scheme);
		i += handle_type(format + i, scheme);
		print_scheme(scheme);
		str = create_format(scheme, ptr);
	}
	ft_lstaddend(list, ft_lstnew(str, ft_strlen(str) + 1));
	printf("----just added %s to the list\n", str);
	free(str);
	scheme_del(&scheme);
	return (i);
}
