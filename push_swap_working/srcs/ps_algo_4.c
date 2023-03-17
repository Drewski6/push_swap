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

int	sort_chunk(t_list **a, t_list **b, t_list **ops, int *bottom_quart)
{
	if (get_bottom_quart_size(a, bottom_quart))
		return (-1);
	if (sort_move_chunk(a, b, ops, bottom_quart))
		return (-1);
	return (0);
}

/*
 *	bottom_quart[0] = holds number of items in the smallest chunk
 *	bottom_quart[1] = value of the upper limit of the smallest chunk
 */

int	sort_rough(t_list **a, t_list **b, t_list **ops)
{
	static int		bottom_quart[2];
	int				a_len;

	a_len = ft_lstsize(*a);
	if (a_len <= 200)
		bottom_quart[0] = (a_len / SMALL_CHUNK_COUNT) - 1;
	else
		bottom_quart[0] = (a_len / BIG_CHUNK_COUNT) - 1;
	while (ft_lstsize(*a) > SMALLEST_ALLOWED_CHUNK)
	{
		if (sort_chunk(a, b, ops, bottom_quart))
			return (-1);
	}
	while (ft_lstsize(*a) > 0)
	{
		if (pb(a, b, ops))
			return (-1);
	}
	return (0);
}

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

int	sort_fine(t_list **a, t_list **b, t_list **ops)
{
	int	cost;
	int	biggest;

	while (ft_lstsize(*b) > 0)
	{
		biggest = ft_lstcmp(*b, &ft_lstcmpgt);
		cost = sort_fine_cost(b, biggest);
		while (cost > 0)
		{
			if (rb(b, ops))
				return (-1);
			cost--;
		}
		while (cost < 0)
		{
			if (rrb(b, ops))
				return (-1);
			cost++;
		}
		if (pa(a, b, ops))
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
