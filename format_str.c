#include "ft_printf.h"

void		width_str(t_scheme *scheme, char **str)
{
	int		len;
	char	*line;

	len = ft_wstrlen(*str);
	if (len < scheme->width)
	{
		if ((line = ft_strnew(scheme->width)))
		{
			if (!scheme->flag->minus)
			{
				printf ("width_str without minus\n");
				ft_memset(line, ' ', scheme->width - len);
				ft_strcpy(line + scheme->width - len, *str);
			}
			else
			{
				ft_strcpy(line, *str);
				ft_memset(line + len, ' ', scheme->width - len);
			}
			free(*str);
			*str = line;
		}
	}
}