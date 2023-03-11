/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/17 10:56:32 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_lstcmp_test(t_list *a, t_list *b)
{
	ft_printf("------------------\n");
	ft_printf("List A\n");
	t_list_print(a, &t_list_print_int, 1);
	ft_printf("Biggest in A %d\n", ft_lstcmp(a, &ft_lstcmpgt));
	ft_printf("Smallest in A %d\n", ft_lstcmp(a, &ft_lstcmplt));
	//ft_printf("Biggest in A is at index %d\n", ft_lstseek_i(a, 0, &ft_lstcmpbg));
	//ft_printf("Smallest in A is at index %d\n", ft_lstseek_i(a, 0, &ft_lstcmpsm));
	ft_printf("List B\n");
	t_list_print(b, &t_list_print_int, 1);
	ft_printf("Biggest in B %d\n", ft_lstcmp(b, &ft_lstcmpgt));
	ft_printf("Smallest in B %d\n", ft_lstcmp(b, &ft_lstcmplt));
	//ft_printf("Biggest in B is at index %d\n", ft_lstseek_i(b, 0, &ft_lstcmpbg));
	//ft_printf("Smallest in B is at index %d\n", ft_lstseek_i(b, 0, &ft_lstcmpsm));
	ft_printf("------------------\n");
}

/*
 * from is b, to is a
 *
 */

int	sort_placement(t_list **lst_src, t_list **lst_dest, t_list **ops)
{
	int	to_biggest_val;
	int	to_smallest_val;
	int	current_val;

	to_biggest_val = ft_lstcmp(*lst_dest, &ft_lstcmpgt);
	to_smallest_val = ft_lstcmp(*lst_dest, &ft_lstcmplt);
	current_val = *(int *)(*lst_src)->content;
	if (current_val < to_biggest_val && current_val < to_smallest_val)
	{
		if(pa(lst_dest, lst_src, ops))
			return (-1);
	}
	else if (current_val > to_biggest_val && current_val > to_smallest_val)
	{
		if(pa(lst_dest, lst_src, ops))
			return (-1);
		if(ra(lst_dest, ops))
			return (-1);
	}
	else
	{
		while (*(int *)(*lst_dest)->content > current_val)
		{
			if(rra(lst_dest, ops))
				return (-1);
		}
		if(pa(lst_dest, lst_src, ops))
			return (-1);
	}
	return (0);
}

/*
 *
 *
 */

int	sort_le_five(t_list **a, t_list **b, t_list **ops, int size)
{
	if (ft_lstseek_i(*a, &ft_lstcmpgt) < 0)
		return (0);
	while (ft_lstsize(*a) > 3)
	{
		if (pb(a, b, ops))
			return (-1);
	}
	if (sort_three(a, ops))
		return (-1);
	while (ft_lstsize(*a) < size)
	{
		//ft_lstcmp_test(*a, *b);
		if (sort_placement(b, a, ops))
			return (-1);
		//ft_lstcmp_test(*a, *b);
	}
	
	return (0);
}
