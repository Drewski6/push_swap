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
