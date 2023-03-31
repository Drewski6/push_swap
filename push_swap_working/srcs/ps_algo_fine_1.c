/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_fine_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:11:49 by dpentlan          #+#    #+#             */
/*   Updated: 2023/03/18 12:11:57 by dpentlan         ###   ########.fr       */
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

int	push_and_swap_pos(t_list **a, t_list **b, t_list **ops, int *value)
{
	while (ft_lstseek_i_by_val(*b, value[0]) >= 0
		|| ft_lstseek_i_by_val(*b, value[1]) >= 0)
	{
		if (*(int *)(*b)->content == value[0]
			|| *(int *)(*b)->content == value[1])
		{
			if (pa(a, b, ops))
				return (-1);
		}
		else
		{
			if (rb(b, ops))
				return (-1);
		}
	}
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
	{
		if (sa(a, ops))
			return (-1);
	}
	return (0);
}

/*
 *
 *
 */

int	push_and_swap_neg(t_list **a, t_list **b, t_list **ops, int *value)
{
	while (ft_lstseek_i_by_val(*b, value[0]) >= 0
		|| ft_lstseek_i_by_val(*b, value[1]) >= 0)
	{
		if (*(int *)(*b)->content == value[0]
			|| *(int *)(*b)->content == value[1])
		{
			if (pa(a, b, ops))
				return (-1);
		}
		else
		{
			if (rrb(b, ops))
				return (-1);
		}
	}
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
	{
		if (sa(a, ops))
			return (-1);
	}
	return (0);
}

/*
 *
 *
 */

int	push_direct(t_list **a, t_list **b, t_list **ops, int *cost)
{
	while (cost[0] > 0)
	{
		if (rb(b, ops))
			return (-1);
		cost[0]--;
	}
	while (cost[0] < 0)
	{
		if (rrb(b, ops))
			return (-1);
		cost[0]++;
	}
	if (pa(a, b, ops))
		return (-1);
	return (0);
}

/*
 *	value[0] = biggest;
 *	value[1] = s_biggest;
 *	value[2] = t_biggest
 *	cost[0] = biggest_cost;
 *	cost[1] = s_biggest_cost;
 *	cost[2] = t_biggest_cost;
 */

int	sort_fine(t_list **a, t_list **b, t_list **ops)
{
	int	value[3];
	int	cost[3];

	while (ft_lstsize(*b) > 1)
	{
		get_cost_value_info(b, cost, value);
		if (cost[0] >= 0 && cost[1] >= 0)
		{
			if (push_and_swap_pos(a, b, ops, value))
				return (-1);
		}
		else if (cost[0] <= 0 && cost[1] <= 0)
		{
			if (push_and_swap_neg(a, b, ops, value))
				return (-1);
		}	
		else
		{
			if (push_direct(a, b, ops, cost))
				return (-1);
		}
	}
	if (ft_lstsize(*b) == 1)
	{
		if (pa(a, b, ops))
			return (-1);
	}
	return (0);
}
