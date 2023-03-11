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

/*
 *
 *
 */

int	sort_cost(t_list **lst_dest, int current_val)
{
	int		i;
	int		dest_len;
	t_list	*current;

	i = 0;
	dest_len = ft_lstsize(*lst_dest);
	current = *lst_dest;
	while (*(int *)(current)->content < current_val)
	{
		i++;
		current = current->next;
	}
	if (dest_len / 2 >= i)
		return (i);
	else
		return (i - dest_len);
}

/*
 *
 *
 */

int	sort_placement_middle(t_list **lst_src, t_list **lst_dest,
	t_list **ops, int current_val)
{
	int	cost;

	cost = sort_cost(lst_dest, current_val);
	while (cost > 0)
	{
		if (ra(lst_dest, ops))
			return (-1);
		cost--;
	}
	while (cost < 0)
	{
		if (rra(lst_dest, ops))
			return (-1);
		cost++;
	}
	if (pa(lst_dest, lst_src, ops))
		return (-1);
	return (0);
}

/*
 *
 *
 */

int	sort_placement_bottom(t_list **lst_src, t_list **lst_dest,
	t_list **ops)
{
	if (sort_recenter(lst_dest, ops))
		return (-1);
	if (pa(lst_dest, lst_src, ops))
		return (-1);
	if (ra(lst_dest, ops))
		return (-1);
	return (0);
}

/*
 *
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
		if (pa(lst_dest, lst_src, ops))
			return (-1);
	}
	else if (current_val > to_biggest_val && current_val > to_smallest_val)
	{
		if (sort_placement_bottom(lst_src, lst_dest, ops))
			return (-1);
	}
	else
	{
		if (sort_placement_middle(lst_src, lst_dest, ops, current_val))
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
	if (sort_le_three(b, ops, size - ft_lstsize(*a), 1))
		return (-1);
	while (ft_lstsize(*a) < size)
	{
		if (sort_placement(b, a, ops))
			return (-1);
	}
	if (sort_recenter(a, ops))
		return (-1);
	return (0);
}
