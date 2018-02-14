#include "ft_printf.h"

void		width_str(t_scheme *scheme, char **str)
{
	int		len;
	char	*line;
	int		i;

	len = ft_wstrlen(*str);
	if (len < scheme->width)
	{
		if ((line = ft_strnew(scheme->width)))
		{
			if (!scheme->flag->minus || scheme->flag->zero)
			{
				i = 0;
				while (i < scheme->width - len)
					line[i++] = scheme->flag->zero ? '0' : ' ';
				ft_strcpy(line + i, *str);
			}
			else
			{
				ft_strcpy(line, *str);
				while (len < scheme->width)
					line[len++] = ' ';
			}
		}
		free(*str);
		*str = line;
	}
}