/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug_tools_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:47:24 by dpentlan          #+#    #+#             */
/*   Updated: 2023/03/11 16:47:37 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ezprint(t_list **lst)
{
	t_list_print(*lst, &t_list_print_int, 1);
}

void	ezprstr(t_list **lst)
{
	t_list_print(*lst, &t_list_print_str, 1);
}

void	ezprstr_c(t_list **lst)
{
	t_list	*current;
	int		i;
	void	(*ptype)(int, t_list *, char);
	int		h_flag;

	ptype = &t_list_print_str;
	h_flag = 1;
	current = *lst;
	i = 0;
	if (h_flag)
		ft_printf("= Index | Value =\n");
	while (i < 5)
	{
		ptype(i, current, h_flag);
		i++;
		current = current->next;
	}
	return ;
}

void	ft_lstcmp_test(t_list *a, t_list *b)
{
	ft_printf("=------------------=\n");
	ft_printf("=List A=\n");
	t_list_print(a, &t_list_print_int, 1);
	ft_printf("=Biggest in A %d=\n", ft_lstcmp(a, &ft_lstcmpgt));
	ft_printf("=Smallest in A %d=\n", ft_lstcmp(a, &ft_lstcmplt));
	ft_printf("=List B=\n");
	t_list_print(b, &t_list_print_int, 1);
	ft_printf("=Biggest in B %d=\n", ft_lstcmp(b, &ft_lstcmpgt));
	ft_printf("=Smallest in B %d=\n", ft_lstcmp(b, &ft_lstcmplt));
	ft_printf("=------------------=\n");
}
