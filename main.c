#include "libftprintf.h"
#include <stdio.h>

# define CYAN		"\x1B[36m"
# define BLUE		"\x1B[34m"
# define RESET		"\x1B[0m"
# define MAGENTA	"\x1B[35m"

int		main(void)
{
	int x1;
	int x2;
	int num;

	num = -777;
	x2 = ft_printf("Privet, Привет, %*.*i and of cause %#.10X\n", 30, 20,
	num, num);
	printf(CYAN);
	x1 = printf("Privet, Привет, %*.*i and of cause %#.10X\n", 30, 20,
	num, num);
	//printf("Privet, Привет, %Aou\n", -8.99999999999999999);
	printf(RESET);
	printf(MAGENTA"my = %i\nor = %i\n" RESET, x2, x1);
}