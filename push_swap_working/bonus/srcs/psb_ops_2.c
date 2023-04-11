/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_ops_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:38:02 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/11 10:44:56 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*	*** sb (swap list b) ***
 *
 *
 */

int	sb_checker(t_list **a, t_list **b)
{
	t_list	*p_b;

	if (!a)
		return (-1);
	p_b = (*b)->next;
	(*b)->next = (*b)->next->next;
	p_b->next = *b;
	*b = p_b;
	return (0);
}

/*	*** rb (rotate list b) ***
 *
 *
 */

int	rb_checker(t_list **a, t_list **b)
{
	t_list	*second;
	t_list	*last;

	if (!a)
		return (-1);
	second = (*b)->next;
	last = ft_lstlast(*b);
	last->next = (*b);
	last->next->next = 0;
	(*b) = second;
	return (0);
}

/*	*** rrb (reverse rotate list b) ***
 *
 *
 */

int	rrb_checker(t_list **a, t_list **b)
{
	t_list	*last;

	if (!a)
		return (-1);
	last = ft_lstlast(*b);
	last->next = (*b);
	(*b) = last;
	while (last->next != *b)
		last = last->next;
	last->next = 0;
	return (0);
}
