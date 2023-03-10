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

t_list	*ft_lstcmpsm(t_list *l1, t_list *l2)
{
	if (!l1 || !l2)
		return (0);
	if (*(int *)l1->content < *(int *)l2->content)
		return (l1);
	return (l2);
}

/*
 *
 *
 */

t_list	*ft_lstcmpbg(t_list *l1, t_list *l2)
{
	if (!l1 || !l2)
		return (0);
	if (*(int *)l1->content > *(int *)l2->content)
		return (l1);
	return (l2);
}

/*
 *
 *
 */

t_list	*ft_lstcmpeq(t_list *l1, t_list *l2)
{
	if (!l1 || !l2)
		return (0);
	if (*(int *)l1->content == *(int *)l2->content)
		return (l1);
	return (0);
}

/*
 *
 *
 */

t_list	*ft_lstseek_a(t_list *l1, t_list *l2, t_list *(*op)(t_list *, t_list *))
{
	t_list	*ret;
	t_list	*current;

	if (!l1)
		return (0);
	ret = l1;
	current = l1;
	while (current->next)
	{
		if (!l2)
		{
			if (op(current, current->next))
				ret = op(current, current->next);
		}
		else
		{
			if (op(current, l2))
				ret = op(current, l2);
		}
		current = current->next;
	}
	return (ret);
}

/*
 *
 *
 */

int	ft_lstseek_i(t_list *l1, t_list *l2, t_list *(*op)(t_list *, t_list *))
{
	t_list	*current;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	current = l1;
	while (current->next)
	{
		if (!l2)
		{
			if (op(current, current->next))
				ret = i;
		}
		else
		{
			if (op(current, l2))
				ret = i;
		}
		current = current->next;
		i++;
	}
	return (ret);
}
