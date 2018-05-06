#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	//ft_printf("%10.7s\n", "love love love");
	int x1 = printf("%.5ls\n", L"люблю Димочку");
	int x2 = ft_printf("%.5ls\n", L"люблю Димочку");
	printf("%i, %i\n", x1, x2);

	//printf("%c\n", NULL);
	return 0;
}