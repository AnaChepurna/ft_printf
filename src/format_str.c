#include "ft_printf.h"

void		width_str(t_scheme *scheme, char **str)
{
	int		len;
	char	*line;

	len = ft_strlen(*str);
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

void		precision_str(t_scheme *scheme, char **str)
{
	char	*line;

	if (ft_strlen(*str) > scheme->precision)
	{
		if ((line = ft_strnew(scheme->precision)))
		{
			ft_strncpy(line, *str, scheme->precision);
			free(*str);
			*str = line;
		}
	}
}

/*int			char_number(wchar_t wc)
{
	
}*/