#include "libftprintf.h"

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	//ft_printf("%10.7s\n", "love love love");
	int x1 = ft_printf("%   Zooo\n");
	int x2 = printf("%   Zooo\n");
	printf("1:%i, 2:%i\n", x1, x2);

	//printf("%c\n", NULL);
	return 0;
}