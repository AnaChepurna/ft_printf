#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	ft_printf("%A\n", 0.0);
	ft_printf("%#20.10a\n", -42.00);
	return 0;
}