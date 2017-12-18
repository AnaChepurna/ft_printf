/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:50:08 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/18 15:14:15 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	a_len(intmax_t n)
{
	size_t	res;

	if (n == 0)
		return (2);
	res = 1;
	if (n < 0)
		res++;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static void		put_a(intmax_t n, char *str, size_t len)
{
	uintmax_t	nb;

	if (n < 0)
		str[0] = '-';
	nb = n < 0 ? -n : n;
	str[len] = '\0';
	len--;
	while (nb >= 10)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	str[len] = nb + '0';
}

char			*ft_itoa(intmax_t n)
{
	char	*res;
	size_t	len;

	len = a_len(n);
	res = (char*)malloc(sizeof(char) * len);
	if (res)
		put_a(n, res, len - 1);
	return (res);
}
