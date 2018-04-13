/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creators.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 20:02:16 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 17:34:08 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_di(t_scheme *scheme, va_list ptr)
{
	char		*str;
	intmax_t	number;
	int		len;

	number = get_i(scheme, ptr);
	str = ft_itoa(number);
	scheme->str = str;
	len = ft_strlen(scheme->str);
	len = scheme->precision <= len ? len : scheme->precision;
	if ((scheme->flag & SIGN) || (scheme->flag & F_PLUS) || (scheme->flag & F_SPACE))
		len++;
	scheme->len = len;
	// if ((scheme->flag & F_ZERO) && (scheme->precision > -1))
	// 	scheme->flag = scheme->flag ^ F_ZERO;
	// if ((scheme->flag & F_PLUS) || (scheme->flag & F_SPACE))
	// 	sign_number(scheme, &str);
	// if (scheme->precision > 0)
	// 	precision_number(scheme, &str);
	// if (!scheme->precision && !number)
	// 	precision_str(scheme, &str);
	// if (scheme->width)
	// 	width_number(scheme, &str);
	// ft_putstr(str);
	// *symbols += ft_strlen(str);
	// free(str);
}

void	create_oux(int *symbols, t_scheme *scheme, va_list ptr)
{
	char		*str;
	int			base;
	uintmax_t	number;

	if (IS_O(scheme->type))
		base = 8;
	else
		base = (IS_X(scheme->type)) ? 16 : 10;
	if ((scheme->flag & F_ZERO) && (scheme->precision > -1))
		scheme->flag = scheme->flag ^ F_ZERO;
	number = get_u(scheme, ptr);
	str = ft_itoa_base(number, base);
	// if (scheme->flag & F_HASH)
	// 	add_base(scheme, &str);
	// if (scheme->precision > 0)
	// 	precision_number(scheme, &str);
	// if (!scheme->precision && !number && !((IS_O(scheme->type)) && scheme->flag & F_HASH))
	// 	precision_str(scheme, &str);
	// if (scheme->width)
	// 	width_number(scheme, &str);
	// if (scheme->type == 'X')
	// 	ft_strcase(str, UP);
	ft_putstr(str);
	*symbols += ft_strlen(str);
	free(str);
}

void	create_p(int *symbols, t_scheme *scheme, va_list ptr)
{
	char	*str;

	str = ft_itoa_base(get_u(scheme, ptr), 16);
	// add_base(scheme, &str);
	// if (scheme->width)
	// 	width_str(scheme, &str);
	ft_putstr(str);
	*symbols += ft_strlen(str);
	free(str);
}

void	create_s(int *symbols, t_scheme *scheme, va_list ptr)
{
	//char	*str;
	void	*s;

	s = get_s(scheme, ptr);
	ft_putstr((char *)s);
	// if (!s)
	// 	str = ft_strdup("(null)");
	// else if (scheme->type == 's')
	// 	str = ft_strdup((char *)s);
	// else
	// {
	// 	str = create_wstr((wchar_t *)s);
	// 	if (!str)
	// 	{
	// 		*symbols = -1;
	// 		return ;
	// 	}
	// }
	// if (scheme->precision > 0)
	// 	precision_str(scheme, &str);
	// if (scheme->width)
	// 	width_str(scheme, &str);
	// ft_putstr(str);
	// *symbols += ft_strlen(str);
	// free(str);
	(void)symbols;
}

void	create_c(int *symbols, t_scheme *scheme, va_list ptr)
{
	//char	*str;
	wchar_t	c;
	//size_t	i[2];

	//str = ft_strdup("!");
	c = get_c(scheme, ptr);
	// if ((scheme->type == 'C' || scheme->size == 'l') && !ft_isascii((int)c))
	// 	*symbols = -1;
	// else
	// {
	// 	if (scheme->width)
	// 		width_str(scheme, &str);
	// 	i[0] = ft_strlen(str);
	// 	if (scheme->flag & F_MINUS)
	// 		str[0] = (char)c;
	// 	else
	// 		str[i[0] - 1] = (char)c;
	// 	i[1] = 0;
	// 	while (i[1] < i[0])
	// 		ft_putchar(str[i[1]++]);
	// 	*symbols += i[0];
	// }
	// free(str);
	ft_putchar(c);
	(void)symbols;
}
