/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:18:05 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/08 10:18:09 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_strunicode(wchar_t *wstr)
{
	char	*str;
	char	*buf1;
	char	*buf2;

	str = ft_strdup("");
	while (*wstr)
	{
		buf1 = str;
		buf2 = get_unicode(*wstr);
		str = ft_strjoin(buf1, buf2);
		//printf("%p\n", buf);
		free(buf1);
		free(buf2);
		wstr++;
	}
	return (str);
}

char	*get_unicode(wchar_t c)
{
	char *str;

	if ((str = ft_strnew(4)))
	{
		if (c <= 127)
			str[0] = c;
		else if (c <= 0x7FF)
		{
			str[0] = (c >> 6) + 0xC0;
			str[1] = (c & 0x3F) + 0x80;
		}
		else if(c <= 0xFFFF)
		{
			str[0] = (c >> 12) + 0xE0;
			str[1] = ((c >> 6) & 0x3F) + 0x80;
			str[2] = (c & 0x3F) + 0x80;
		}
		else if (c <= 0x10FFFF)
		{
			str[0] = (c >> 18) + 0xF0;
			str[1] = ((c >> 12) & 0x3F) + 0x80;
			str[2] = ((c >> 6) & 0x3F) + 0x80;
			str[3] = (c & 0x3F) + 0x80;
		}
	}
	return (str);
}
