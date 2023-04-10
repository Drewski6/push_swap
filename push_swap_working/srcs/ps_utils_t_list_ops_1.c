/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_t_list_ops_1.c                            :+:      :+:    :+:   */
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
