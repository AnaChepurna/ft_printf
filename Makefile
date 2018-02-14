CC = gcc
CFLAG = -Wall -Wextra -Werror 
NAME = ft_printf
SRC = 	main.c \
		create_format.c \
		creators_numbers.c \
		format_numbers.c \
		format_str.c \
		ft_printf.c \
		handle_format.c \
		handle_line.c \
		handlers.c \
		scheme_new.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(SRC) libft/libft.a -o $(NAME)

fclean: 
	rm $(NAME)

dir:
	make -C libft

re: fclean dir all
