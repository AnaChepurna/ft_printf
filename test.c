/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:30 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/15 20:07:37 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	test(int c, ...)
{
	va_list ptr;

	va_start(ptr, c);
	printf("test do: %s\n", get_int_octal(ptr));
}

int main(void)
{
//	unsigned int n = 88;
	printf("printf do: %u\n", -88);
	test(2, -88);
}
