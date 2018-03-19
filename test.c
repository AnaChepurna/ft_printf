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

	int x1 = printf("%c, %c, %C, %C, %lc, %C\n", 't', NULL, NULL, L't', L't', L'Т');
	int x2 = ft_printf("%c, %c, %C, %C, %lc, %C\n", 't', NULL, NULL, L't', L't', L'Т');
	//int x2 = ft_printf("%f, $love %C %c\n", d, wchar, c);

	printf("%i - %i\n", x1, x2);
}
