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

int	sort_top_three(t_list **a, t_list **ops)
{
	int	first;
	int	second;
	int	third;
	int	ret;

	first = *(int *)(*a)->content;
	second = *(int *)(*a)->next->content;
	third = *(int *)(*a)->next->next->content;
	ret = 0;
	if (first < second && second < third && third > first)
		return (0);
	else if (first > second && second < third && third > first)
		ret = sa(a, ops);
	else if (first > second && second > third && third < first)
		ret = sort_multi_ops(a, ops, 5, &sa, &ra, &sa, &rra, &sa);
	else if (first > second && second < third && third < first)
		ret = sort_multi_ops(a, ops, 4, &sa, &ra, &sa, &rra);
	else if (first < second && second > third && third > first)
		ret = sort_multi_ops(a, ops, 3, &ra, &sa, &rra);
	else if (first < second && second > third && third < first)
		ret = sort_multi_ops(a, ops, 4, &ra, &sa, &rra, &sa);
	if (ret < 0)
		return (-1);
	return (0);
}

/*
 *
 *
 */

int	check_post_push(t_list **a, t_list **ops)
{
	if (ft_lstsize(*a) == 1)
		return (0);
	if (ft_lstsize(*a) == 2)
	{
		if (*(int *)(*a)->content >
			*(int *)(*a)->next->content)
		{
			if (sa(a, ops))
				return (-1);
		}
	}
	if (ft_lstsize(*a) >= 3)
	{
		if (sort_top_three(a, ops))
			return (-1);
	}
	return (0);
}

/*
 *
 *
 */

int	(push_direct_push_logic(t_list **a, t_list **b, int *value, int *cost))
{
	return (*(int *)(*b)->content == value[0]
			|| *(int *)(*b)->content == value[1]
			|| ((*(int *)(*b)->content == value[2]
			&& ft_lstsize(*a) > 0
			&& *(int *)(*a)->content == value[1])
			&& cost[0] > 0));
}

/*
 *
 *
 */

int	push_direct(t_list **a, t_list **b, t_list **ops)
{
	int	value[3];
	int	cost[3];
	int	(*op)(t_list **, t_list **);
	int	pushes;

	pushes = 0;
	get_cost_value_info(b, cost, value);
	op = &rrb;
	if (cost[0] >= 0)
		op = &rb;
	while (ft_lstseek_i_by_val(*b, value[0]) != -1)
	{
		if (push_direct_push_logic(a, b, value, cost))
		{
			if (pa(a, b, ops))
				return (-1);
			pushes++;
		}
		else
		{
			if (op(b, ops))
				return (-1);
		}
	}
	return (pushes);
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
	int	pushes;

	pushes = 0;
	while (ft_lstsize(*b) > 3)
	{
		pushes = push_direct(a, b, ops);
		if (pushes == -1)
			return (-1);
		if (check_post_push(a, ops))
			return (-1);
	}
	pushes = 0;
	while (ft_lstsize(*b) > 0)
	{
		if (pa(a, b, ops))
			return (-1);
		pushes++;
	}
	if (check_post_push(a, ops))
		return (-1);
	return (0);
}
