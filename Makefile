# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achepurn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 15:48:34 by achepurn          #+#    #+#              #
#    Updated: 2018/03/22 19:57:54 by achepurn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror 
NAME = libftprintf.a
LIB = ./libft/
SRC = ./src/
INCL = ./incl
SRC_SRC = creators_core.c \
		creators_adds.c \
		format_numbers.c \
		format_str.c \
		format_floats.c \
		ft_printf.c \
		handle_format.c \
		handle_line.c \
		handlers.c \
		scheme_new.c \
		getters_core.c \
		getters_adds.c \
		format_adds.c \
		format_floats2.c
SRC_LIB = ft_lstprint.c	ft_striter.c ft_lstrm.c ft_striteri.c \
	  ft_arrtolst.c ft_memalloc.c ft_strjoin.c ft_atoi.c \
	  ft_memccpy.c ft_strlcat.c ft_atoi_base.c ft_memchr.c \
	  ft_strlen.c ft_atoll.c ft_memcmp.c ft_strmap.c ft_bzero.c	\
	  ft_memcpy.c ft_strmapi.c ft_isalnum.c	ft_memdel.c	ft_strncat.c \
	  ft_isalpha.c ft_memmove.c	ft_strncmp.c ft_isascii.c ft_memset.c \
	  ft_strncpy.c ft_isdigit.c ft_putchar.c ft_strnequ.c ft_isprint.c \
	  ft_putchar_fd.c ft_strnew.c ft_itoa.c ft_putendl.c ft_strnstr.c \
	  ft_itoa_base.c ft_putendl_fd.c ft_strrchr.c ft_lstadd.c ft_putnbr.c \
	  ft_lstaddend.c ft_putnbr_fd.c ft_arrfree.c ft_wstrlen.c\
	  ft_lstaddindex.c	ft_putstr.c	ft_strsplit.c ft_lstdel.c ft_putstr_fd.c \
	  ft_strsplitlst.c ft_lstdelone.c ft_strcat.c ft_strstr.c \
	  ft_lstget.c ft_strchr.c ft_strsub.c ft_lstgetindex.c ft_strclr.c \
	  ft_strtrim.c ft_lstiter.c ft_strcmp.c ft_tolower.c ft_lstlen.c \
	  ft_strcpy.c ft_toupper.c ft_lstmap.c ft_strdel.c ft_memclr.c \
	  ft_lstnew.c ft_strdup.c ft_lstpop.c ft_strequ.c ft_strcase.c
OBJ = $(addprefix $(LIB), $(SRC_LIB:.c=.o)) $(addprefix $(SRC), $(SRC_SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c 
	$(CC) -c $(CFLAG) -I $(INCL) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
