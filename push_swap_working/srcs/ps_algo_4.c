/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:27:39 by dpentlan          #+#    #+#             */
/*   Updated: 2023/03/11 21:27:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 *
 */

int	sort_fine_cost(t_list **lst, int current_val)
{
	int		i;
	int		lst_len;
	t_list	*current;

	i = 0;
	lst_len = ft_lstsize(*lst);
	current = *lst;
	while (*(int *)(current)->content != current_val)
	{
		i++;
		current = current->next;
	}
	if (lst_len / 2 >= i)
		return (i);
	else
		return (i - lst_len);
}

/*
 *
 *
 */

int	get_bottom_quart_size(t_list **a, int *bottom_quart)
{
	t_list	*c;

	// duplicate lst a to lst b
	// find the smallest in a that is larger than the largest in c.
	// copy to end of c.
	// save value of (size of a / 4) to bottom_quart[0]
	// save value at index (size of a / 4) to bottom_quart[1]
	// return 0 on success.
	return (0);
}

/*
 *
 *
 */

int	sort_chunk(t_list **a, t_list **ops)
{
	int		bottom_quart[2];
	int		i;

	i = 0;
	if (get_bottom_quart_size(a, bottom_quart))
		return (-1);
	while (i < bottom_quart[0])
	{
		if (*(int *)(*a)->content < bottom_quart[1])
		{
			if (pb(a, b, ops))
				return (-1);
			i++;
		}
		else
		{
			if (ra(a, ops))
				return (-1);
		}
	}
	return (0);
}

/*
 *
 *
 */

int	sort_fine(t_list **a, t_list **b, t_list **ops)
{
	int	cost;
	int	biggest;

	while (ft_lstsize(b) > 0)
	{
		biggest = ft_lstcmp(b, &ft_lstcmpgt);
		cost = sort_fine_cost(b, biggest);
		while (cost > 0)
		{
			if (rb(lst_dest, ops))
				return (-1);
			cost--;
		}
		while (cost < 0)
		{
			if (rrb(lst_dest, ops))
				return (-1);
			cost++;
		}
		if (pa(a, b, ops))
			return (-1)
	}
	return (0);
}

/*
 *
 *
 */

int	sort_rough(t_list **a, t_list **b, t_list **ops)
{
	int	lst_a_len;

	while (ft_lstsize(a) > 10)
	{
		if (sort_chunk(a, ops))
			return (-1);
	}
	while (ft_lstsize(a) > 0)
	{
		if (pb(a, ops))
			return (-1);
	}
	return (0);
}

/*
 *
 *
 */

int	sort_gt_five(t_list **a, t_list **b, t_list **ops)
{
	if (sort_rough(a, b, ops))
		return (-1);
	if (sort_fine(a, b, ops))
		return (-1);
	return (0);
}
