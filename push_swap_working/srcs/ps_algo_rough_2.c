/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_rough_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:58:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/03/14 09:58:47 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 *
 */

t_list	*ft_lstseek_a_by_i(t_list **lst, int index)
{
	int		i;	
	t_list	*node;

	i = 0;
	if (index < 0 || !lst)
		return (0);
	node = *lst;
	while (i < index && node)
	{
		node = node->next;
		i++;
	}
	if (!node)
		return (0);
	return (node);
}

/*
 *
 *
 */

int	ft_lstdel_and_relink_by_index(t_list **lst, int index)
{
	t_list	*del_target;

	if (index == 0)
	{
		del_target = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(del_target, &t_list_free_content);
	}
	else if (index < 1 || index > ft_lstsize(*lst) + 1)
		return (-1);
	else
	{
		del_target = ft_lstseek_a_by_i(lst, index);
		ft_lstseek_a_by_i(lst, index - 1)->next = del_target->next;
		ft_lstdelone(del_target, &t_list_free_content);
	}
	return (0);
}

/*
 *
 *
 */

int	ft_lstseek_i_by_val(t_list *lst, int val)
{
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	while (current)
	{
		if (*(int *)current->content == val)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

/*
 *
 *
 */

t_list	*ft_lstsort(t_list *lst)
{
	int		smallest_i;
	t_list	*sorted;
	t_list	*new;
	t_list	*buf;

	sorted = 0;
	while (lst)
	{
		smallest_i = ft_lstseek_i_by_val(lst, ft_lstcmp(lst, &ft_lstcmplt));
		buf = ft_lstseek_a_by_i(&lst, smallest_i);
		if (!buf)
			return (0);
		new = ft_lstdup_node(buf);
		ft_lstadd_back(&sorted, new);
		ft_lstdel_and_relink_by_index(&lst, smallest_i);
	}
	ft_lstclear(&lst, &t_list_free_content);
	return (sorted);
}
