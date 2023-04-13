/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_ops_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:56:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/11 10:43:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*	*** sa (swap list a) ***
 *
 *
 */

int	sa_checker(t_list **a, t_list **b)
{
	t_list	*p_a;

	if (!(*a) || !b)
		return (0);
	p_a = (*a)->next;
	(*a)->next = (*a)->next->next;
	p_a->next = *a;
	*a = p_a;
	return (0);
}

/*	*** ra (rotate list a) ***
 *
 *
 */

int	ra_checker(t_list **a, t_list **b)
{
	t_list	*second;
	t_list	*last;

	if (!(*a) || !b)
		return (0);
	second = (*a)->next;
	last = ft_lstlast(*a);
	last->next = (*a);
	last->next->next = 0;
	(*a) = second;
	return (0);
}

/*	*** rra (reverse rotate list a) ***
 *
 *
 */

int	rra_checker(t_list **a, t_list **b)
{
	t_list	*last;

	if (!(*a) || !b)
		return (0);
	last = ft_lstlast(*a);
	last->next = (*a);
	(*a) = last;
	while (last->next != *a)
		last = last->next;
	last->next = 0;
	return (0);
}
