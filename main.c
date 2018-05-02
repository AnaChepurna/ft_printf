#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	//int x = ft_printf("%#.o %#.0o", 0, 0);
//ft_printf("@moulitest: %#.o %#.0o", 0, 0);
 //ft_printf("%lld", -9223372036854775808);
	//printf("%i\n", x);
	//ft_printf("|%g|\n", 2147480000.0);
	printf("\n---------------------------------\n");
	//printf("%.o %.0o", 0, 0);
	//printf("@moulitest: %#.o %#.0o", 0, 0);
	printf("%.2d\n", 4242);
	printf("%.2i\n", 4242);
	ft_printf("%.2d\n", 4242);
	ft_printf("%.2i\n", 4242);
	//printf("|%g|\n", 4200000000000.0);
	//printf("|%g|\n", 42000.42);
	//ft_printf("%.0G\n", 42000.4242424242);
	//printf("%.0G\n", 42.42);
	return 0;
}