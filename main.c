#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	int x = ft_printf("%%");
	printf("%i\n", x);
	//ft_printf("|%g|\n", 2147480000.0);
	printf("---------------------------------\n");
	//printf("|%g|\n", 4200000000000.0);
	//printf("|%g|\n", 42000.42);
	//ft_printf("%.0G\n", 42000.4242424242);
	//printf("%.0G\n", 42.42);
	return 0;
}