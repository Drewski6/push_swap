/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:49:01 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/15 10:49:03 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	*** t_list_print (type list (struct) print) ***
 *
 *	Prints all the values in a list for debugging purposes.
 *	Takes a pointer to a list start.
 *	Returns nothing.
 */

void	t_list_print(t_list *start)
{
	t_list	*current;
	int		i;

	current = start;
	i = 0;
	ft_printf("Index | Value\n");
	while (current)
	{
		ft_printf("%5d | %d\n", i, *(int *)current->content);
		i++;
		current = current->next;
	}
	return ;
}

/*	*** table_print (print table) ***
 *
 *	Prints the contents of a table (char **).
 *	Takes a char table (char **).
 *	Returns nothing.
 */

void	table_print(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		ft_printf("[%02d] %s\n", i, table[i]);
		i++;
	}
	return ;
}
