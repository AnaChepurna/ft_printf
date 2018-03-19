/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:30 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 18:23:51 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include "libftprintf.h"
#include "incl/ft_printf.h"

int main(void)
{
	double d = -1.55;

	printf("%f, %e, %a\n", d, d, d);

	char	str[8];
	int i = 0;
	while (i < 8)
	{
		str[i] = ((long long int *)&d)[8 - i];
		i++;
	}
	ft_printf("%f, %e, %a\n", d, d, d);
}
