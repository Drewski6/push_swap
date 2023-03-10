/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:56:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/15 14:57:07 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*** sa (swap list a) ***
 *
 *
 */

int	sa(t_list **a, t_list **ops)
{
	t_list	*p_a;

	p_a = (*a)->next;
	(*a)->next = (*a)->next->next;
	p_a->next = *a;
	*a = p_a;
	if (t_list_ops_add(ops, "sa\n"))
		return (-1);
	return (0);
}

/*	*** ra (rotate list a) ***
 *
 *
 */

int	ra(t_list **a, t_list **ops)
{
	t_list	*second;
	t_list	*last;

	second = (*a)->next;
	last = ft_lstlast(*a);
	last->next = (*a);
	last->next->next = 0;
	(*a) = second;
	if (t_list_ops_add(ops, "ra\n"))
		return (-1);
	return (0);
}

/*	*** rra (reverse rotate list a) ***
 *
 *
 */

int	rra(t_list **a, t_list **ops)
{
	t_list	*last;

	last = ft_lstlast(*a);
	last->next = (*a);
	(*a) = last;
	while (last->next != *a)
		last = last->next;
	last->next = 0;
	if (t_list_ops_add(ops, "rra\n"))
		return (-1);
	return (0);
}
