/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_ops_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:38:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/11 10:48:34 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*	*** pa (push to list a (from list b)) ***
 *
 *
 */

int	pa_checker(t_list **a, t_list **b)
{
	t_list	*second_b;

	if (!(*b))
		return (0);
	second_b = (*b)->next;
	(*b)->next = (*a);
	(*a) = (*b);
	(*b) = second_b;
	return (0);
}

/*	*** pb (push to list b (from list a)) ***
 *
 *
 */

int	pb_checker(t_list **a, t_list **b)
{
	t_list	*second_a;

	if (!(*a))
		return (0);
	second_a = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = second_a;
	return (0);
}

/*	*** ss (swap list a and b) ***
 *
 *
 */

int	ss_checker(t_list **a, t_list **b)
{
	t_list	*p_a;
	t_list	*p_b;

	if (!(*a) || !(*b))
		return (0);
	p_a = (*a)->next;
	(*a)->next = (*a)->next->next;
	p_a->next = *a;
	*a = p_a;
	p_b = (*b)->next;
	(*b)->next = (*b)->next->next;
	p_b->next = *b;
	*b = p_b;
	return (0);
}

/*	*** rr (rotate list a and b) ***
 *
 *
 */

int	rr_checker(t_list **a, t_list **b)
{
	t_list	*second_a;
	t_list	*last_a;
	t_list	*second_b;
	t_list	*last_b;

	if (!(*a) || !(*b))
		return (0);
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
	return (0);
}

/*	*** rrr (reverse rotate list a and b) ***
 *
 *
 */

int	rrr_checker(t_list **a, t_list **b)
{
	t_list	*last_a;
	t_list	*last_b;

	if (!(*a) || !(*b))
		return (0);
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
	return (0);
}
