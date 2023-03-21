/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_rough_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:27:39 by dpentlan          #+#    #+#             */
/*   Updated: 2023/03/11 21:27:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 *
 */

int	sort_move_chunk(t_list **a, t_list **b,
	t_list **ops, int *chunk_info)
{
	int	i;
	int	a_len;

	i = 0;
	a_len = ft_lstsize(*a);
	while (i < a_len)
	{
		if (*(int *)(*a)->content <= chunk_info[1])
		{
			if (pb(a, b, ops))
				return (-1);
		}
		else
		{
			if (ra(a, ops))
				return (-1);
		}
		i++;
	}
	return (0);
}

/*
 *
 *	chunk_info[0] = holds number of items in the smallest chunk
 *	chunk_info[1] = value of the upper limit of the smallest chunk
 *	chunk_info[2] = value of the lower limit of the largest chunk
 */

int	get_chunk_info(t_list **a, int *chunk_info)
{
	t_list	*c;
	t_list	*c_sorted;
	int		a_len;

	a_len = ft_lstsize(*a);
	c = ft_lstdup_lst(*a);
	if (!c)
		return (-1);
	c_sorted = ft_lstsort(c);
	if (a_len > chunk_info[0])
		chunk_info[1] = *(int *)ft_lstseek_a_by_i(&c_sorted,
				chunk_info[0])->content;
	else
		chunk_info[1] = *(int *)ft_lstlast(c_sorted)->content;
	ft_lstclear(&c_sorted, &t_list_free_content);
	return (0);
}

/*
 *
 *
 */

int	sort_chunk(t_list **a, t_list **b, t_list **ops, int *chunk_info)
{
	if (get_chunk_info(a, chunk_info))
		return (-1);
	if (sort_move_chunk(a, b, ops, chunk_info))
		return (-1);
	return (0);
}

/*
 *	chunk_info[0] = holds number of items in the smallest chunk
 *	chunk_info[1] = value of the upper limit of the smallest chunk.
 *			Acts like a high-pass filter.
 *	chunk_info[2] = value of the lower limit of the largest chunk.
 *			Acts like a low-pass filter.
 */

int	sort_rough(t_list **a, t_list **b, t_list **ops)
{
	static int		chunk_info[3];
	int				a_len;

	a_len = ft_lstsize(*a);
	if (a_len <= 200)
		chunk_info[0] = (a_len / SMALL_CHUNK_COUNT) - 1;
	else
		chunk_info[0] = (a_len / BIG_CHUNK_COUNT) - 1;
	while (ft_lstsize(*a) > SMALLEST_ALLOWED_CHUNK)
	{
		if (sort_chunk(a, b, ops, chunk_info))
			return (-1);
	}
	while (ft_lstsize(*a) > 0)
	{
		if (pb(a, b, ops))
			return (-1);
	}
	return (0);
}

/*
 *
 *
 */

int	sort_gt_five(t_list **a, t_list **b, t_list **ops)
{
	if (sort_rough(a, b, ops))
		return (-1);
	if (sort_fine(a, b, ops))
		return (-1);
	return (0);
}
