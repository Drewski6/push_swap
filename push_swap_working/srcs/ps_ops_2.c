/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:38:02 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/17 08:38:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*** sb (swap list b) ***
 *
 *
 */

int	sb(t_list **b, t_list **ops)
{
	t_list	*p_b;

	p_b = (*b)->next;
	(*b)->next = (*b)->next->next;
	p_b->next = *b;
	*b = p_b;
	if (t_list_ops_add(ops, "sb\n"))
		return (-1);
	return (0);
}

/*	*** rb (rotate list b) ***
 *
 *
 */

int	rb(t_list **b, t_list **ops)
{
	t_list	*second;
	t_list	*last;

	second = (*b)->next;
	last = ft_lstlast(*b);
	last->next = (*b);
	last->next->next = 0;
	(*b) = second;
	if (t_list_ops_add(ops, "rb\n"))
		return (-1);
	return (0);
}

/*	*** rrb (reverse rotate list b) ***
 *
 *
 */

int	rrb(t_list **b, t_list **ops)
{
	t_list	*last;

	last = ft_lstlast(*b);
	last->next = (*b);
	(*b) = last;
	while (last->next != *b)
		last = last->next;
	last->next = 0;
	if (t_list_ops_add(ops, "rrb\n"))
		return (-1);
	return (0);
}
