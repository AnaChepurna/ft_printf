/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:30 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/25 18:23:51 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include "libft/libft.h"

/*typedef		struct  s_scheme
{
	void	(*f)(int i);
}					t_scheme; 

void		print_number(int i)
{
	ft_putchar('0' + i);
}

void		run(t_list *lst)
{
	t_scheme	*scheme;
	static int	i = 0;

	scheme = (t_scheme *)lst->content;
	scheme->f(i);
	i++;
} */

int main(void)
{
	/*t_list 		*funcs;
	t_scheme	*s;
	t_list		*lst;
	int			i;

	funcs = NULL;
	i = 0;
	while (i < 6)
	{
		lst = ft_lstnew(NULL, 0);
		s = (t_scheme *)malloc(sizeof(t_scheme));
		s->f = &print_number;
		lst->content = (void *)s;
		ft_lstadd(&funcs, lst);
		i++;
	}
	ft_lstiter(funcs, &run); */
	//char string[4]={ 0x61, 0x81, 0x61, 0 };
	wchar_t *wc = L"Привет!!č";
	while (*wc)
	{
		//printf("%d\n", *wc);
		wprintf("---%lc\n", *wc);
		wc++;
	}
	char *text = (char *)wc;
	//printf("%s\n", string);
	printf("%S", wc);
}
