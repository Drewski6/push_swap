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

/*	*** t_list_print_str (type list (struct) print string) ***
 *
 *	Used with t_list_print when printing strings.
 *	Takes an index 'i' and a t_list struct 'current' and a header flag 'h_flag'
 *	which turns on headers if active.
 *	Returns nothing.
 */

void	t_list_print_str(int i, t_list *current, char h_flag)
{
	if (h_flag)
		ft_printf("=%5d | %s=", i, (char *)current->content);
	else
		ft_putstr_fd((char *)current->content, 1);
}

/*	*** t_list_print_int (type list (struct) print integer) ***
 *
 *	Used with t_list_print when printing integers.
 *	Takes an index 'i' and a t_list struct 'current' and a header flag 'h_flag'
 *	which turns on headers if active.
 *	Returns nothing.
 */

void	t_list_print_int(int i, t_list *current, char h_flag)
{
	if (h_flag)
		ft_printf("=%5d | %d=\n", i, *(int *)current->content);
	else
		ft_printf("%d ", *(int *)current->content);
}

/*	*** t_list_print (type list (struct) print) ***
 *
 *	Prints all the values in a list for debugging purposes.
 *	Takes a pointer to a list start, a function pointer depending the type of
 *	content to print, and a header flag 'h_flag' which turns 
 *	on headers if active.
 *	Returns nothing.
 */

void	t_list_print(t_list *start, void (*ptype)(int, t_list *,
			char), char h_flag)
{
	t_list	*current;
	int		i;

	current = start;
	i = 0;
	if (h_flag)
		ft_printf("=Index | Value=\n");
	while (current)
	{
		ptype(i, current, h_flag);
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
		ft_printf("=[%02d] %s=\n", i, table[i]);
		i++;
	}
	return ;
}

void	ezprint(t_list **lst)
{
	t_list_print(*lst, &t_list_print_int, 1);
}

void	ezprstr(t_list **lst)
{
	t_list_print(*lst, &t_list_print_str, 1);
}
