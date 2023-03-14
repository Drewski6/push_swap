/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_5.c                                        :+:      :+:    :+:   */
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

void	ft_lstdup_clear(t_list **lst)
{
	t_list	*current;
	t_list	*next_node;

	if (lst == 0)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*lst = 0;
}

/*
 *
 *
 */

t_list	*ft_lstseek_by_index(t_list **lst, int index)
{
	int		i;	
	t_list	*node;

	i = 0;
	node = *lst;
	while (i < index && node)
	{
		node = node->next;
	}
	if(!node)
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

	if (index < 1 || index > ft_lstsize(*lst) + 1)
		return (-1);
	del_target = ft_lstseek_by_index(lst, index);
	ft_lstseek_by_index(lst, index - 1)->next = del_target->next;
	free(del_target);
	return (0);
}

/*
 *
 *
 */

t_list	*ft_lstsort(t_list *lst)
{
	int		i;
	t_list	*current;
	int		smallest_i;
	t_list	*sorted;

	i = 0;
	current = lst;
	while (current)
	{
		smallest_i = ft_lstseek_i(lst, &ft_lstcmplt);
		ft_lstadd_back(&sorted, ft_lstseek_by_index(&lst, smallest_i));
		ft_lstdel_and_relink_by_index(&lst, smallest_i);
	}
	ft_lstdup_clear(&lst);
	return (lst);
}

/*
 *
 *
 */

t_list	*ft_lstdup(t_list *lst_old)
{
	t_list *lst_new;
	int		i;
	t_list	*current;

	i = 0;
	current = lst_old;
	while (current)
	{
		lst_new = ft_lstnew(current->content);
		if (!lst_new)
			return (0);
		ft_lstadd_back(&lst_old, lst_new);
		current = current->next;
	}
	return (lst_new);
}

/*
 *
 *
 */

int	get_bottom_quart_size(t_list **a, int *bottom_quart)
{
	t_list	*c;
	t_list	*c_sorted;

	c = ft_lstdup(*a);
	if (!c)
		return (-1);
	c_sorted = ft_lstsort(c);
	bottom_quart[0] = ft_lstsize(*a) / 4;
	bottom_quart[1] = *(int *)ft_lstseek_by_index(&c_sorted, bottom_quart[0])->content;
	return (0);
}
