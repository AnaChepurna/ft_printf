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

	num = 11;
	x2 = ft_printf("Privet, %.4hi\n", num);
	x1 = printf(CYAN "Privet, %.4hi\n" RESET, num);
	printf(MAGENTA"my = %i\nor = %i\n" RESET, x2, x1);
}