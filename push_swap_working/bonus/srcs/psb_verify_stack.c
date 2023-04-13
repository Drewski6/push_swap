/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_verify_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:34:41 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/10 17:35:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//int	(*)(t_list **, t_list **)psb_check_input(char *input)
void	*psb_check_input(char *input)
{
	if (!ft_strncmp(input, "sa\n", 3))
		return ((void *)&sa_checker);
	else if (!ft_strncmp(input, "ra\n", 3))
		return ((void *)&ra_checker);
	else if (!ft_strncmp(input, "rra\n", 4))
		return ((void *)&rra_checker);
	else if (!ft_strncmp(input, "sb\n", 3))
		return ((void *)&sb_checker);
	else if (!ft_strncmp(input, "rb\n", 3))
		return ((void *)&rb_checker);
	else if (!ft_strncmp(input, "rrb\n", 4))
		return ((void *)&rrb_checker);
	else if (!ft_strncmp(input, "pa\n", 3))
		return ((void *)&pa_checker);
	else if (!ft_strncmp(input, "pb\n", 3))
		return ((void *)&pb_checker);
	else if (!ft_strncmp(input, "ss\n", 3))
		return ((void *)&ss_checker);
	else if (!ft_strncmp(input, "rr\n", 3))
		return ((void *)&rr_checker);
	else if (!ft_strncmp(input, "rrr\n", 4))
		return ((void *)&rrr_checker);
	return (0);
}

int	psb_read_inst(t_list **a, t_list **b)
{
	char	*stdin_line;
	t_list	*ops;

	ops = 0;
	stdin_line = get_next_line(0, 0);
	while (stdin_line)
	{
		if (!psb_check_input(stdin_line))
		{
			free(stdin_line);
			ft_lstclear(&ops, &t_list_free_content);
			return (-1);
		}
		if (t_list_ops_add(&ops, stdin_line))
		{
			free(stdin_line);
			ft_lstclear(&ops, &t_list_free_content);
			return (-1);
		}
		free(stdin_line);
		stdin_line = get_next_line(0, 0);
	}
	free(stdin_line);
	if (psb_exec_inst(a, b, &ops))
	{
		free(get_next_line(0, 1));
		ft_lstclear(&ops, &t_list_free_content);
		return (-1);
	}
	free(get_next_line(0, 1));
	ft_lstclear(&ops, &t_list_free_content);
	return (0);
}

/*
 *
 *
 */

int	psb_exec_inst(t_list **a, t_list **b, t_list **ops)
{
	int		(*ret)(t_list **, t_list **);
	t_list	*current;

	current = *ops;
	while (current)
	{
		ret = (int (*)(t_list **, t_list **))psb_check_input(current->content);
		if (!ret)
			return (-1);
		if (ret(a, b))
			return (-1);
		current = current->next;
	}
	return (0);
}

/*
 *
 *
 */

int	psb_check_sort(t_list **a, t_list **b)
{
	if (sort_is_sorted(a) && ft_lstsize(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
