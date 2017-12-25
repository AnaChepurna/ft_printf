/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:18:53 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 16:50:36 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct	s_flag
{
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;	
}				t_flag;

typedef struct	s_scheme
{
	t_flag		*flag;
	int			width;
	int			precision;
	char		*size;
	char		type;
}				t_scheme;

t_scheme		*scheme_new(void);
void			handle_format(const char **format, t_list **list);
void			handle_line(const char **format, t_list **list);

#endif
