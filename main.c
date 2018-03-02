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
	unsigned int  num;
	//int		*p;

	num = 335298840;
	//p = &num;
	//char *str = "Привет";
	x2 = ft_printf("Privet, Привет, %b %u||\n", num, num);
	printf(CYAN);
	x1 = printf("Privet, Привет,%u||\n", num);
	//printf("Privet, Привет, %Aou\n", -8.99999999999999999);
	printf(RESET);
	printf(MAGENTA"my = %i\nor = %i\n" RESET, x2, x1);
}
//66666 66666 666
//187ae 147ae 148 