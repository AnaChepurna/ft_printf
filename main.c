#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	ft_printf("|%g|\n", 42.42);
	printf("|%g|\n", 42.42);
	printf("---------------------------------\n");
	//printf("|%g|\n", 4200000000000.0);
	//printf("|%g|\n", 42000.42);
	ft_printf("%.10g\n", 42000.4242424242);
	printf("%.10g\n", 42000.4242424242);
	return 0;
}