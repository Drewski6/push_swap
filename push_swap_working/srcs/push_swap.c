/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/01/30 14:37:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* *** main (push swap) ***
 *
 *	Entry point for push_swap program.
 */

int	main(int argc, char **argv)
{
	t_list	*a;

	a = 0;
	if (argc == 1)
		return (0);
	a = arg_switch(a, argc, argv);
	if (!a)
	{
		error();
		return (-1);
	}
	if (sort_is_sorted(&a))
	{
		ft_lstclear(&a, &t_list_free_content);
		return (0);
	}
	if (sort_entry(&a))
	{
		error();
		return (-1);
	}
	ft_lstclear(&a, &t_list_free_content);
	return (0);
}
