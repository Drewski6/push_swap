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

/*
 *
 *
 */

int	sort_multi_ops(t_list **lst, t_list **ops, int size, ...)
{
	va_list	parg;
	int		(*op)(t_list **, t_list **);
	int		i;

	i = 0;
	va_start(parg, size);
	while (i < size)
	{
		op = va_arg(parg, int (*)(t_list **, t_list **));
		if (op(lst, ops))
		{
			va_end(parg);
			return (-1);
		}
		i++;
	}
	va_end(parg);
	return (0);
}

/*	***  () ***
 *
 *
 */

int	sort_three(t_list **a, t_list **ops)
{
	int	first;
	int	second;
	int	third;
	int	ret;

	first = *(int *)(*a)->content;
	second = *(int *)(*a)->next->content;
	third = *(int *)(*a)->next->next->content;
	ret = 0;
	if (first < second && second < third && third > first)
		return (0);
	else if (first > second && second < third && third > first)
		ret = sa(a, ops);
	else if (first > second && second > third && third < first)
		ret = sort_multi_ops(a, ops, 2, &sa, &rra);
	else if (first > second && second < third && third < first)
		ret = ra(a, ops);
	else if (first < second && second > third && third > first)
		ret = sort_multi_ops(a, ops, 2, &sa, &ra);
	else if (first < second && second > third && third < first)
		ret = rra(a, ops);
	if (ret < 0)
		return (-1);
	return (0);
}

/*	*** sort_le_three (sort less than or equal to three) ***
 *
 *	Manages sorting when the list is less than or equal to 3 items.
 *	Takes the list 'a' a list of operations 'ops' and the size 'size' of the
 *	list.
 *	Returns 0 on success or -1 on ERROR.
 */

int	sort_le_three(t_list **lst, t_list **ops, int size, int stack)
{
	if (size == 1)
		return (0);
	else if (size == 2)
	{
		if (*(int *)(*lst)->content < *(int *)(*lst)->next->content)
			return (0);
		if (stack == 0)
		{
			if (sa(lst, ops))
				return (-1);
		}
		else
		{
			if (sb(lst, ops))
				return (-1);
		}
	}
	else if (size == 3)
	{
		if (sort_three(lst, ops))
			return (-1);
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
	int		ret;
	t_list	*ops;
	t_list	*b;

	ret = 0;
	ops = 0;
	b = 0;
	size = ft_lstsize(*a);
	if (size <= 3)
		ret = sort_le_three(a, &ops, size, 0);
	else if (size <= 5)
		ret = sort_le_five(a, &b, &ops, size);
	else
		ret = sort_gt_five(a, &b, &ops);
	ft_lstclear(&b, &t_list_free_content);
	if (ret < 0)
	{
		ft_lstclear(&ops, &t_list_free_content);
		return (-1);
	}
	t_list_print(ops, &t_list_print_str, 0);
	ft_lstclear(&ops, &t_list_free_content);
	return (0);
}
