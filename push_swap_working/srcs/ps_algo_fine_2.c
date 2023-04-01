/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_fine_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:30:25 by dpentlan          #+#    #+#             */
/*   Updated: 2023/03/31 17:30:53 by dpentlan         ###   ########.fr       */
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

int	get_cost_value_info(t_list **lst, int *cost, int *value)
{
	value[0] = ft_lstcmp(*lst, &ft_lstcmpgt);
	value[1] = find_next_biggest(lst, value[0]);
	value[2] = find_next_biggest(lst, value[1]);
	cost[0] = sort_fine_cost(lst, value[0]);
	cost[1] = sort_fine_cost(lst, value[1]);
	cost[2] = sort_fine_cost(lst, value[2]);
	return (0);
}
