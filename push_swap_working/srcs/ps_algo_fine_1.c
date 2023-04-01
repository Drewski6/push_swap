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
 *
 *
 */

int	biggest_in_array(size_t size, int *array)
{
	int	biggest;
	size_t	i;

	i = 0;
	biggest = array[i];
	while (i < size)
	{
		if (array[i] > biggest)
			biggest = array[i];
		i++;
	}
	return (biggest);
}

int	smallest_in_array(size_t size, int *array)
{
	int	smallest;
	size_t	i;

	i = 0;
	smallest = array[i];
	while (i < size)
	{
		if (array[i] < smallest)
			smallest = array[i];
		i++;
	}
	return (smallest);
}

/*
 *
 *
 */

int	ft_abs(int value)
{
	if (value < 0)
		value = value * -1;
	return (value);
}

/*
 *
 *
 */

int	init_array(size_t size, int *array)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		array[i] = 0;
		i++;
	}
	return (0);
}

/*
 *
 *
 */

int	cost_sort_three_shortest(int lst_size, size_t size, int *array)
{
	int		positives[3];
	int		negatives[3];
	int		pos_offset;
	int		neg_offset;
	size_t	i;

	i = 0;
	init_array(3, positives);
	init_array(3, negatives);
	while (i < size)
	{
		if (array[i] >= 0)
			positives[i] = array[i];
		else
			negatives[i] = array[i];
		i++;
	}
	pos_offset = biggest_in_array(3, positives);
	neg_offset = ft_abs(smallest_in_array(3, negatives));
	if ((pos_offset * 2) + neg_offset > lst_size)
	{}
	else
	{}
	return (pos_offset + neg_offset);
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
	int	cost_return;

	while (ft_lstsize(*b) > 1)
	{
		get_cost_value_info(b, cost, value);
		cost_return = cost_sort_three_shortest(ft_lstsize(*b), 3, cost);
		if (cost_return) {}
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
