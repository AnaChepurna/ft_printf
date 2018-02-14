/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:18:53 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/12 18:20:50 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libftprintf.h"

# define CYAN		"\x1B[36m"
# define BLUE		"\x1B[34m"
# define RESET		"\x1B[0m"
# define MAGENTA	"\x1B[35m"

# define IS_NUMBER(c) (c) >= '0' && (c) <= '9'
# define IS_DI(n) (n) == 'd' || (n) == 'D' || (n) == 'i'
# define IS_OU(n)  (n) == 'o' || (n) == 'O' || (n) == 'u' || (n) == 'U'
# define IS_X(n) (n) == 'x' || (n) == 'X'

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
	int			size;
	int			type;
}				t_scheme;

/*
 **cheme_new.c
*/
t_scheme		*scheme_new(void);
void			scheme_del(t_scheme **s);
void			print_scheme(t_scheme *s);

/*
 **handle_format.c
*/
int				handle_format(const char *format, t_list **list, va_list ptr);

/*
 **handle_line.c
*/
int				handle_line(const char *format, t_list **list);

/*
 **handlers.c
*/
int				handle_width(const char *format, t_scheme *scheme,
		va_list ptr);
int				handle_precision(const char *format, t_scheme *scheme);
int				handle_flags(const char *format, t_flag *flag);
int				handle_size(const char *format, t_scheme *scheme);
int				handle_type(const char *format, t_scheme *scheme);

/*
 **create_format.c
*/
char			*create_format(t_scheme *scheme, va_list ptr);

/*
 **creators _numbers.c
*/
char			*create_di(t_scheme *scheme, va_list ptr);
char			*create_ou(t_scheme *scheme, va_list ptr);
char			*create_x(t_scheme *scheme, va_list ptr);

/*
 **format _numbers.c
*/
void			precision_number(int precision, char **str);

/*
 **format _str.c
*/
void			width_str(t_scheme *scheme, char **str);

#endif
