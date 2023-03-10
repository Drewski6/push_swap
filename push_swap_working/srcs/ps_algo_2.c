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

void ft_lstcmp_test(t_list **a, t_list **b)
{
	ft_printf("------------------\n");
	ft_printf("List A\n");
	t_list_print(*a, &t_list_print_int, 1);
	ft_printf("Biggest in A %d\n", *(int *)ft_lstseek_a(*a, 0, &ft_lstcmpbg)->content);
	ft_printf("Smallest in A %d\n", *(int *)ft_lstseek_a(*a, 0, &ft_lstcmpsm)->content);
	//ft_printf("Biggest in A is at index %d\n", ft_lstseek_i(*a, 0, &ft_lstcmpbg));
	//ft_printf("Smallest in A is at index %d\n", ft_lstseek_i(*a, 0, &ft_lstcmpsm));
	ft_printf("List B\n");
	t_list_print(*b, &t_list_print_int, 1);
	ft_printf("Biggest in B %d\n", *(int *)ft_lstseek_a(*b, 0, &ft_lstcmpbg)->content);
	ft_printf("Smallest in B %d\n", *(int *)ft_lstseek_a(*b, 0, &ft_lstcmpsm)->content);
	//ft_printf("Biggest in B is at index %d\n", ft_lstseek_i(*b, 0, &ft_lstcmpbg));
	//ft_printf("Smallest in B is at index %d\n", ft_lstseek_i(*b, 0, &ft_lstcmpsm));
	ft_printf("------------------\n");
}

/*
 * from is b, to is a
 *
 */

int	sort_placement(t_list **lst_from, t_list **lst_to, t_list **ops)
{
	int	to_biggest_val;
	int	to_smallest_val;
	int	current_val;

	to_biggest_val = *(int *)ft_lstseek_a(*lst_to, 0, &ft_lstcmpbg)->content;
	to_smallest_val = *(int *)ft_lstseek_a(*lst_to, 0, &ft_lstcmpsm)->content;
	current_val = *(int *)(*lst_from)->content;
	if (current_val < to_biggest_val && current_val < to_smallest_val)
	{
		if(pa(lst_to, lst_from, ops))
			return (-1);
	}
	else if (current_val > to_biggest_val && current_val > to_smallest_val)
	{
		if(pa(lst_to, lst_from, ops))
			return (-1);
		if(ra(lst_to, ops))
			return (-1);
	}
	else
	{
		while (*(int *)(*lst_to)->content > current_val)
		{
			if(rra(lst_to, ops))
				return (-1);
		}
		if(pa(lst_to, lst_from, ops))
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
	if (ft_lstseek_i(*a, 0, &ft_lstcmpbg) < 0)
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
		//ft_lstcmp_test(a, b);
		if (sort_placement(b, a, ops))
			return (-1);
	}
	
	return (0);
}
