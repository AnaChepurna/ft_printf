#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	//setlocale(LC_ALL, "");
	//ft_printf("%10.7s\n", "love love love");
		int x1 = ft_printf("{%g}", 2147480000.0);
	int x2 = printf("{%g}", 2147480000.0);
	ft_printf("{%g}", 0.0);
	// int x1 = ft_printf("{%S}", L"привет, Дiiiiiима");
	// int x2 = printf("{%S}", L"привет, Дiiiiiима");
	printf("1:%i, 2:%i\n", x1, x2);

	//printf("%c\n", NULL);
	return 0;
}