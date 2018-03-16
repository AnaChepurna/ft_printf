/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:48:25 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/16 15:48:27 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "incl/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <wchar.h>
# include <math.h>

int				ft_printf(const char *restrict format, ...);

#endif
