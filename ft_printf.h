/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:18:53 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/18 18:54:46 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

# define TYPE_EQU(c) ft_strequ(scheme->type, (c))

typedef struct	s_arg
{
	char	*type;
	char	*size;
	char	*(*f)(va_list ptr);
}				t_arg;

char	*get_int_decimal(va_list ptr);
char	*get_int_octal(va_list ptr);
t_arg	**init_specs(void);

#endif
