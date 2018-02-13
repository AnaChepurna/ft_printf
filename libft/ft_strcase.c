#include "libft.h"

void		ft_strcase(char *s, int x)
{
	size_t	i;

	if (!s || (x != 1 && x != 0))
		return ;
	i = 0;
	while (s[i])
	{
		s[i] = x ? ft_toupper((int)s[i]) : ft_tolower((int)s[i]);
		i++;
	}
}