/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:05:49 by dpentlan          #+#    #+#             */
/*   Updated: 2023/03/11 13:06:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 *
 */

int	sort_is_sorted(t_list **lst)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *lst;
	while (current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		i++;
		current = current->next;
	}
	return (1);
}

/*
 *
 *
 */

int	sort_recenter_cost(t_list **lst_dest)
{
	int		smallest;
	int		dest_len;
	int		i;
	t_list	*current;

	i = 0;
	current = *lst_dest;
	smallest = ft_lstcmp(*lst_dest, &ft_lstcmplt);
	dest_len = ft_lstsize(*lst_dest);
	while (*(int *)current->content != smallest)
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

int	sort_recenter(t_list **lst_dest, t_list **ops)
{
	int	cost;

	cost = sort_recenter_cost(lst_dest);
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
	return (0);
}
