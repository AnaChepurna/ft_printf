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
	wchar_t wchar = L'r';
	wchar_t *wstr = L"oh nice!";
	char *str = "Привет!!!";
	char c = *str;

	printf("%2$10a, %01$+30.3a\n", 3.14, 678.55555565);

	ft_printf("%10a, %0+30.3a\n", 3.14, 678.55555565);
	
	//printf("%i - %i\n", x1, x2);
}
