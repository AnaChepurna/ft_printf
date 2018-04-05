/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creators_adds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:47:46 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/16 15:47:48 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_fe(int *symbols, t_scheme *scheme, va_list ptr)
{
	char		*str;
	long double	number;

	number = get_f(scheme, ptr);
	if (!(str = handle_naninf(number)))
	{
		if (IS_F(scheme->type))
			str = create_float(scheme, number);
		else if (IS_E(scheme->type))
			str = create_exponent(scheme, number);
		else
			str = ft_strdup("nope");
			// str = create_hexfloat(scheme, number);
		// if ((scheme->flag & F_PLUS) || (scheme->flag & F_SPACE))
		// 	sign_number(scheme, &str);
		// if (scheme->width)
		// 	width_str(scheme, &str);
	}
	ft_putstr(str);
	*symbols += ft_strlen(str);
	free(str);
}

void	create_b(int *symbols, t_scheme *scheme, va_list ptr)
{
	uintmax_t		number;
	int				size;
	unsigned char	*str;
	char			*line;

	number = get_u(scheme, ptr);
	size = get_size(scheme);
	str = (unsigned char *)&number;
	line = ft_strdup("");
	while (--size >= 0)
		binary_format(str[size], &line, size != 0);
	if (scheme->precision > -1)
		binary_precision(scheme, &line);
	if (scheme->width)
		width_number(scheme, &line);
	ft_putstr((char *)line);
	*symbols += ft_strlen((char *)str);
	free(line);
}

void	create_n(int *symbols, va_list ptr)
{
	int		*n;

	n = get_n(ptr);
	*n = *symbols;
}

/*void	create_blanc(int *symbols, t_scheme *scheme)
{
	char	*str;

	str = ft_strdup("!");
	if (scheme->width)
		width_str(scheme, &str);
	if (scheme->flag & F_MINUS)
		ft_putstr(str + 1);
	else
		str[i[0] - 1] = (char)c;
	i[1] = 0;
	while (i[1] < i[0])
		ft_putchar(str[i[1]++]);
	*symbols += i[0];
	}
	free(str);
} */
