/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:30 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/18 14:59:02 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	get_big(int c, ...)
{
	va_list ptr;

	va_start(ptr, c);
	va_arg(ptr, int);
	return(va_arg(ptr, int));
}

void	test(int c, ...)
{
	va_list ptr;

	va_start(ptr, c);
	printf("test do: %s\n", get_int_octal(ptr));
}

int main(void)
{
	printf("i is: %ji\n", 22);
	test(2, -88);
}
