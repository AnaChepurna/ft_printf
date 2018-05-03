#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	ft_printf("%10.7s\n", "love love love");
	printf("%lc\n", L'Л');
	//printf("%c\n", NULL);
	return 0;
}