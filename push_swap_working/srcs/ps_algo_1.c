/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:51:37 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/16 08:51:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*** sort_le_three (sort less than or equal to three) ***
 *
 *	Manages sorting when the list is less than or equal to 3 items.
 *	Takes the list 'a' a list of operations 'ops' and the size 'size' of the
 *	list.
 *	Returns 0 on success or -1 on ERROR.
 */

int	sort_le_three(t_list **a, t_list **ops, int size)
{
	if (size == 1)
		return (0);
	else if (size == 2)
	{
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			return (0);
		if (sa(a, ops))
			return (-1);
	}
	else if (size == 3)
	{
	}
	return (0);
}

/*	*** sort_entry (sort entry) ***
 *
 *	Entry point for the sorting algorithm.
 *	Takes t_list pointer to beginning of first stack and buffer
 *	for instruction list.
 *	Returns 0 on success or -1 on ERROR.
 */

int	sort_entry(t_list **a)
{
	int		size;
	t_list	*ops;

	ops = 0;
	size = ft_lstsize(*a);
	if (size <= 3)
	{
		if (sort_le_three(a, &ops, size))
		{
			ft_lstclear(&ops, &t_list_free_content);
			return (-1);
		}
	}
	else if (size <= 6)
	{
		ft_printf("Size is less than or equal to 6.\n");
	}
	else
	{
		ft_printf("Size is greater than 6.\n");
	}
	t_list_print(*a, &t_list_print_int, 1);
	t_list_print(ops, &t_list_print_str, 0);
	ft_lstclear(&ops, &t_list_free_content);
	return (0);
}
