#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	ft_printf("%a\n", 42.00);
	ft_printf("%#20.10a\n", 42.00);
	return 0;
}