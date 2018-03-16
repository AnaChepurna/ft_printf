#include "libftprintf.h"
#include <stdio.h>

# define CYAN		"\x1B[36m"
# define BLUE		"\x1B[34m"
# define RESET		"\x1B[0m"
# define MAGENTA	"\x1B[35m"

int		main(void)
{
	//int x1;
	//nt x2;
	//unsigned int  num;
	//int		*p;

	//num = 335298840;
	//p = &num;
	//char *str = "Привет";
	int a = 0;
	int x = ft_printf("%");
	int x2 = printf("%");
	//printf(CYAN);
	//printf("%#-08x", 42);
	//printf("Privet, Привет, %Aou\n", -8.99999999999999999);
	//printf(RESET);
	printf(MAGENTA"my = %i\nor = %i\n" RESET, x, x2);
}
//66666 66666 666
//187ae 147ae 148 ./