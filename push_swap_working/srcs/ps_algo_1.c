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

int	sort_two_ops(t_list **a, t_list **ops,
		int (*op1)(t_list **, t_list **),
		int (*op2)(t_list **, t_list **))
{
	if (op1(a, ops))
		return (-1);
	if (op2(a, ops))
		return (-1);
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
		ret = sort_two_ops(a, ops, &sa, &rra);
	else if (first > second && second < third && third < first)
		ret = ra(a, ops);
	else if (first < second && second > third && third > first)
		ret = sort_two_ops(a, ops, &sa, &ra);
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

int	sort_le_three(t_list **a, t_list **ops, int size)
{
	if (size == 1)
		return (0);
	else if (size == 2)
	{
		if (*(int *)(*a)->content < *(int *)(*a)->next->content)
			return (0);
		if (sa(a, ops))
			return (-1);
	}
	else if (size == 3)
	{
		if (sort_three(a, ops))
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
		ret = sort_le_three(a, &ops, size);
	else if (size <= 5)
		ret = sort_le_five(a, &b, &ops, size);
	else
		ft_printf("Size is greater than 5.\n");
	ft_lstclear(&b, &t_list_free_content);
	if (ret < 0)
	{
		ft_lstclear(&ops, &t_list_free_content);
		return (-1);
	}
	t_list_print(*a, &t_list_print_int, 0);
	//ft_printf("\n");
	//t_list_print(ops, &t_list_print_str, 1);
	ft_lstclear(&ops, &t_list_free_content);
	return (0);
}

//	t_list_print(ops, &t_list_print_str, 0);
