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

# include "../libftprintf.h"

# define CYAN		"\x1B[36m"
# define BLUE		"\x1B[34m"
# define RESET		"\x1B[0m"
# define MAGENTA	"\x1B[35m"

# define IS_NUMBER(c) (c) >= '0' && (c) <= '9'
# define IS_I(n) (n) == 'd' || (n) == 'D' || (n) == 'i'
# define IS_O(n) (n) == 'o' || (n) == 'O'
# define IS_U(n) (n) == 'u' || (n) == 'U'
# define IS_X(n) (n) == 'x' || (n) == 'X'
# define IS_C(n) (n) == 'c' || (n) == 'C'
# define IS_S(n) (n) == 's' || (n) == 'S'
# define IS_F(n) (n) == 'f' || (n) == 'F' || (n) == 'g'
# define IS_E(n) (n) == 'e' || (n) == 'E' //|| (n) == 'G'
# define IS_A(n) (n) == 'a' || (n) == 'A'
# define IS_B(n) (n) == 'b'

# define F_MINUS	1
# define F_PLUS 	2
# define F_SPACE	4
# define F_HASH		8
# define F_ZERO		16
# define SIGN		32
# define ALT1		64
# define ALT2		128

typedef struct	s_scheme
{
	int			flag;
	int			width;
	int			precision;
	int			size;
	int			type;
	int			order;
	char		*str;
	int			len;
}				t_scheme;

void			print_scheme(t_scheme *scheme);

/*
 **cheme_new.c
*/
t_scheme		*scheme_new(void);
void			scheme_del(t_scheme **s);

/*
 **handle_format.c
*/
int				handle_format(const char *format, int *symbols, va_list ptr);

/*
 **handle_line.c
*/
int				handle_line(const char *format, int *symbols);

/*
 **handlers.c
*/
int				handle_width(const char *format, t_scheme *scheme,
		va_list ptr);
int				handle_precision(const char *format, t_scheme *scheme,
		va_list ptr);
int				handle_flags(const char *format, t_scheme *scheme);
int				handle_size(const char *format, t_scheme *scheme);
int				handle_type(const char *format, t_scheme *scheme);

/*
 **creators_core.c
*/
void			create_di(t_scheme *scheme, va_list ptr);
void			create_oux(t_scheme *scheme, va_list ptr);
void			create_p(t_scheme *scheme, va_list ptr);
void			create_s(int *symbols, t_scheme *scheme, va_list ptr);
void			create_c(int *symbols, t_scheme *scheme, va_list ptr);

/*
 **creators_adds.c
*/
void			create_fe(int *symbols, t_scheme *scheme, va_list ptr);
void			create_b(int *symbols, t_scheme *scheme, va_list ptr);
void			create_n(int *symbols, va_list ptr);

/*
 **format _numbers.c
*/
void			precision_number(t_scheme *scheme, char **str);
void			width_number(t_scheme *scheme, char **str);
void			sign_number(t_scheme *scheme, char **str);
void			add_base(t_scheme *scheme, char **str);

/*
 **format _str.c
*/
void			width_str(t_scheme *scheme, char **str);
void			precision_str(t_scheme *scheme, char **str);

/*
 **format_float.c
*/
char			*create_float(t_scheme *scheme, long double number);
char			*create_exponent(t_scheme *scheme, long double number);
int				double_to_int(long double number);

/*
 **format_float2s.c
*/
char			*create_hexfloat(t_scheme *scheme, long double number);

/*
 **format_adds.c
*/
char			*handle_naninf(long double number);
int				get_size(t_scheme *scheme);
void			binary_format(unsigned char	c, char **line, int space);
void			binary_precision(t_scheme *scheme, char **str);
char			*create_wstr(wchar_t *ptr);

/*
 **getters_core.c
*/
intmax_t		get_i(t_scheme *scheme, va_list prt);
uintmax_t		get_u(t_scheme *scheme, va_list prt);
wchar_t			get_c(t_scheme *scheme, va_list prt);
void			*get_s(t_scheme *scheme, va_list prt);

/*
 **getters_adds.c
*/
long double		get_f(t_scheme *scheme, va_list ptr);
int				*get_n(va_list prt);

#endif
