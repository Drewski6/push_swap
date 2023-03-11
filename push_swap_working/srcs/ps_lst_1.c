/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:20:24 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/17 17:20:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 *
 */

int	ft_lstcmplt(int cmp, int ref)
{
	return (cmp < ref);
}

/*
 *
 *
 */

int	ft_lstcmpgt(int cmp, int ref)
{
	return (cmp > ref);
}

/*
 *
 *
 */

int	ft_lstcmp(t_list *lst, int (*op)(int, int))
{
	int		ret;
	t_list	*current;

	if (!lst)
		return (0);
	ret = *(int *)lst->content;
	current = lst;
	while (current->next)
	{
		if (op(*(int *)current->content, ret))
			ret = *(int *)current->content;
		current = current->next;
	}
	if (op(*(int *)current->content, ret))
		ret = *(int *)current->content;
	return (ret);
}

/*
 *
 *
 */

int	ft_lstseek_i(t_list *lst, int (*op)(int, int))
{
	t_list	*current;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	current = lst;
	while (current->next)
	{
		if (op(*(int *)current->content,
				*(int *)current->next->content))
			ret = i;
		current = current->next;
		i++;
	}
	return (ret);
}
