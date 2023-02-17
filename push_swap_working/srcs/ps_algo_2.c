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
	ft_printf("List B\n");
	t_list_print(*b, &t_list_print_int, 1);
	ft_printf("Biggest in A %d\n", *(int *)ft_lstseek_a(*a, 0, &ft_lstcmpbg)->content);
	ft_printf("Biggest in B %d\n", *(int *)ft_lstseek_a(*b, 0, &ft_lstcmpbg)->content);
	ft_printf("Smallest in A %d\n", *(int *)ft_lstseek_a(*a, 0, &ft_lstcmpsm)->content);
	ft_printf("Smallest in B %d\n", *(int *)ft_lstseek_a(*b, 0, &ft_lstcmpsm)->content);
	ft_printf("Biggest in A is at index %d\n", ft_lstseek_i(*a, 0, &ft_lstcmpbg));
	ft_printf("Biggest in B is at index %d\n", ft_lstseek_i(*b, 0, &ft_lstcmpbg));
	ft_printf("Smallest in A is at index %d\n", ft_lstseek_i(*a, 0, &ft_lstcmpsm));
	ft_printf("Smallest in B is at index %d\n", ft_lstseek_i(*b, 0, &ft_lstcmpsm));
	ft_printf("------------------\n");
}

/*
 *
 *
 */

/*
int	sort_cost(t_list *a, t_list *b, t_list *current)
{


	return (0);
}
*/

/*
 *
 *
 */

int	sort_le_five(t_list **a, t_list **b, t_list **ops, int size)
{
	//t_list	*current;

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
		//current = *b;
		// algo here lol
		ft_lstcmp_test(a, b);
		if (pa(a, b, ops))
			return (-1);
	}
	return (0);
}
