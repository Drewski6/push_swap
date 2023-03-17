/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:31:49 by dpentlan          #+#    #+#             */
/*   Updated: 2023/03/16 15:31:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 *
 */

t_list	*ft_lstdup_node(t_list *src)
{
	void	*content_new;
	t_list	*current_new;

	content_new = t_list_alloc_content(*(int *)src->content);
	if (!content_new)
		return (0);
	current_new = ft_lstnew(content_new);
	if (!current_new)
		return (0);
	return (current_new);
}

/*
 *
 *
 */

t_list	*ft_lstdup_lst(t_list *lst_old)
{
	t_list	*lst_new;
	t_list	*current;
	t_list	*current_new;

	lst_new = ft_lstdup_node(lst_old);
	if (!lst_new)
		return (0);
	current = lst_old->next;
	while (current)
	{
		current_new = ft_lstdup_node(current);
		if (!current_new)
			return (0);
		ft_lstadd_back(&lst_new, current_new);
		current = current->next;
	}
	return (lst_new);
}

/*
 *
 *
 */

int	sort_move_chunk(t_list **a, t_list **b,
	t_list **ops, int *bottom_quart)
{
	int	i;
	int	a_len;

	i = 0;
	a_len = ft_lstsize(*a);
	while (i < a_len)
	{
		if (*(int *)(*a)->content < bottom_quart[1])
		{
			if (pb(a, b, ops))
				return (-1);
		}
		else
		{
			if (ra(a, ops))
				return (-1);
		}
		i++;
	}
	return (0);
}
