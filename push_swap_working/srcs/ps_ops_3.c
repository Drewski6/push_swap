/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:38:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/17 08:38:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*** pa (push to list a (from list b)) ***
 *
 *
 */

int		pa(t_list **a, t_list **b, t_list **ops)
{
	t_list	*second_b;

	second_b = (*b)->next;
	(*b)->next = (*a);
	(*a) = (*b);
	(*b) = second_b;
	if (t_list_ops_add(ops, "pa\n"))
		return (-1);
	return (0);
}

/*	*** pb (push to list b (from list a)) ***
 *
 *
 */

int		pb(t_list **a, t_list **b, t_list **ops)
{
	t_list	*second_a;

	second_a = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = second_a;
	if (t_list_ops_add(ops, "pb\n"))
		return (-1);
	return (0);
}

/*	*** ss (swap list a and b) ***
 *
 *
 */

int	ss(t_list **a, t_list **b, t_list **ops)
{
	t_list	*p_a;
	t_list	*p_b;

	p_a = (*a)->next;
	(*a)->next = (*a)->next->next;
	p_a->next = *a;
	*a = p_a;
	p_b = (*b)->next;
	(*b)->next = (*b)->next->next;
	p_b->next = *b;
	*b = p_b;
	if (t_list_ops_add(ops, "ss\n"))
		return (-1);
	return (0);
}

/*	*** rr (rotate list a and b) ***
 *
 *
 */

int	rr(t_list **a, t_list **b, t_list **ops)
{
	t_list	*second_a;
	t_list	*last_a;
	t_list	*second_b;
	t_list	*last_b;

	second_a = (*a)->next;
	last_a = ft_lstlast(*a);
	last_a->next = (*a);
	last_a->next->next = 0;
	(*a) = second_a;
	second_b = (*b)->next;
	last_b = ft_lstlast(*b);
	last_b->next = (*b);
	last_b->next->next = 0;
	(*b) = second_b;
	if (t_list_ops_add(ops, "rr\n"))
		return (-1);
	return (0);
}

/*	*** rrr (reverse rotate list a and b) ***
 *
 *
 */

int	rrr(t_list **a, t_list **b, t_list **ops)
{
	t_list	*last_a;
	t_list	*last_b;

	last_a = ft_lstlast(*a);
	last_a->next = (*a);
	(*a) = last_a;
	while (last_a->next != *a)
		last_a = last_a->next;
	last_a->next = 0;
	last_b = ft_lstlast(*b);
	last_b->next = (*b);
	(*b) = last_b;
	while (last_b->next != *b)
		last_b = last_b->next;
	last_b->next = 0;
	if (t_list_ops_add(ops, "rrr\n"))
		return (-1);
	return (0);
}
