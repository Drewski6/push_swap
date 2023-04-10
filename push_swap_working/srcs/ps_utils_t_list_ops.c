/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_t_list_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:22:33 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/16 11:22:35 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*** t_list_ops_add (type list (struct) operations add) ***
 *
 *	Adds a new operation to the list of operations performed.
 *	Takes a pointer to beginning of operations list and a string
 *	to add as content to list.
 *	Returns 0 on success or -1 on ERROR.
 *
 *	NOTE: This function does not free the string, it duplicates it,
 *	so it is best to pass a string on the stack (not heap) like this:
 *	t_list_ops_add(ops, "ps\n");
 */

int	t_list_ops_add(t_list **ops, char *content)
{
	t_list	*new_op;
	char	*new_content;

	new_op = 0;
	if (!content || !*content || !ops)
		return (-1);
	new_content = ft_strdup(content);
	if (!new_content)
		return (-1);
	new_op = ft_lstnew(new_content);
	if (!new_op)
		return (-1);
	ft_lstadd_back(ops, new_op);
	return (0);
}

/*	optimization works like this:
 *	| head | -> | head + 1 | -> | head + 2 | -> | head + 3 |
 *	
 *	check content of head + 1 and head + 2 
 */

int	ops_del_two_and_replace(t_list **head, char *content)
{
	t_list	*new_op;
	char	*new_content;
	t_list	*head_plus_three;

	head_plus_three = (*head)->next->next->next;
	ft_lstdelone((*head)->next->next, &t_list_free_content);
	ft_lstdelone((*head)->next, &t_list_free_content);
	new_content = ft_strdup(content);
	if (!new_content)
		return (-1);
	new_op = ft_lstnew(new_content);
	if (!new_op)
		return (-1);
	(*head)->next = new_op;
	(*head)->next->next = head_plus_three;
	return (0);
}

/*
 *
 *
 */

int	optimize_lst_ss(t_list **head)
{
	t_list	*current;

	current = *head;
	if ((!strncmp(current->next->content, "sa\n", 3)
		&& !strncmp(current->next->next->content, "sb\n", 3))
		|| (!strncmp(current->next->content, "sb\n", 3)
		&& !strncmp(current->next->next->content, "sa\n", 3)))
	{
		if (ops_del_two_and_replace(&current, "ss\n"))
			return (-1);
	}
	return (0);
}

/*
 *
 *
 */

int	optimize_lst_rr(t_list **head)
{
	t_list	*current;

	current = *head;
	if ((!strncmp(current->next->content, "ra\n", 3)
		&& !strncmp(current->next->next->content, "rb\n", 3))
		|| (!strncmp(current->next->content, "rb\n", 3)
		&& !strncmp(current->next->next->content, "ra\n", 3)))
	{
		if (ops_del_two_and_replace(&current, "rr\n"))
			return (-1);
	}
	return (0);
}

/*
 *
 *
 */

int	optimize_lst_rrr(t_list **head)
{
	t_list	*current;

	current = *head;
	if ((!strncmp(current->next->content, "rra\n", 4)
		&& !strncmp(current->next->next->content, "rrb\n", 4))
		|| (!strncmp(current->next->content, "rrb\n", 4)
		&& !strncmp(current->next->next->content, "rra\n", 4)))
	{
		if (ops_del_two_and_replace(&current, "rrr\n"))
			return (-1);
	}
	return (0);
}

int	optimize_list_entry(t_list **ops)
{
	t_list	*head;

	head = *ops;
	while (head->next->next->next)
	{
		if (optimize_lst_ss(&head))
			return (-1);
		if (optimize_lst_rr(&head))
			return (-1);
		if (optimize_lst_rrr(&head))
			return (-1);
		head = head->next;
	}
	return (0);
}
