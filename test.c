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
	int	n;
	int n2;

	printf("%f, %e, %a%n\n", d, d, d, &n);

	ft_printf("%f, %e, %a%n\n", d, d, d, &n2);

	printf("%i, %i\n", n, n2);
}
