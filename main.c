#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	ft_printf("%20.10d\n", -42);
	ft_printf("%+20.10d\n", 42);
	return 0;
}