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

int	find_next_biggest(t_list **lst, int value)
{
	int		ret;
	int		i;
	t_list	*current;

	i = 0;
	current = (*lst);
	if (*(int *)current->content == value)
		ret = 1;
	else
		ret = 0;
	while (current)
	{
		if (*(int *)current->content
			> *(int *)ft_lstseek_a_by_i(lst, ret)->content
			&& *(int *)current->content < value)
			ret = i;
		current = current->next;
		i++;
	}
	return (*(int *)ft_lstseek_a_by_i(lst, ret)->content);
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

int	push_and_swap_pos(t_list **a, t_list **b, t_list **ops, int *cost)
{
	while (ft_lstseek_i_by_val(*b, cost[0]) >= 0
		|| ft_lstseek_i_by_val(*b, cost[1]) >= 0)
	{
		if (*(int *)(*b)->content == cost[0]
			|| *(int *)(*b)->content == cost[1])
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

int	push_and_swap_neg(t_list **a, t_list **b, t_list **ops, int *cost)
{
	while (ft_lstseek_i_by_val(*b, cost[0]) >= 0
		|| ft_lstseek_i_by_val(*b, cost[1]) >= 0)
	{
		if (*(int *)(*b)->content == cost[0]
			|| *(int *)(*b)->content == cost[1])
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
	while (cost[2] > 0)
	{
		if (rb(b, ops))
			return (-1);
		cost[2]--;
	}
	while (cost[2] < 0)
	{
		if (rrb(b, ops))
			return (-1);
		cost[2]++;
	}
	if (pa(a, b, ops))
		return (-1);
	return (0);
}

/*
 *	cost[0] = biggest;
 *	cost[1] = s_biggest;
 *	cost[2] = biggest_cost;
 *	cost[3] = s_biggest_cost;
 */

int	sort_fine(t_list **a, t_list **b, t_list **ops)
{
	int	cost[4];

	while (ft_lstsize(*b) > 1)
	{
		cost[0] = ft_lstcmp(*b, &ft_lstcmpgt);
		cost[1] = find_next_biggest(b, cost[0]);
		cost[2] = sort_fine_cost(b, cost[0]);
		cost[3] = sort_fine_cost(b, cost[1]);
		if (cost[2] >= 0 && cost[3] >= 0)
		{
			if (push_and_swap_pos(a, b, ops, cost))
				return (-1);
		}
		else if (cost[2] <= 0 && cost[3] <= 0)
		{
			if (push_and_swap_neg(a, b, ops, cost))
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
