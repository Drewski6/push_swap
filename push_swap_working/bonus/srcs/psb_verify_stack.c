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

int	psb_read_inst(t_list **lst)
{
	char	*stdin_line;

	if (lst) {}
	stdin_line = get_next_line(0);
	while (stdin_line)
	{
		// check for valid input string here
			// if good, continue loop
			// if bad, print error, free stdin_line from before and return. free list. free all
		free(stdin_line);
		stdin_line = get_next_line(0);
	}
	return (0);
}

/*
 *
 *
 */

int	psb_check_sort(t_list **a)
{
	if (sort_is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
