#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	ft_printf("%C\n", L'Л');
	printf("%lc\n", L'Л');
	//printf("%c\n", NULL);
	return 0;
}