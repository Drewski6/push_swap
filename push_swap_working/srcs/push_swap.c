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

/*	*** error (error and close) ***
 *
 *	Displays "Error\n" to the terminal.
 */

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

/*	*** arg_switch (argument switch) ***
 *
 *	Acts as a switch for which functions to use for parsing the arguments.
 *	Takes an int 'argc' from main and a table of args 'argv' from main.
 *	Returns address to t_list 'a' on success or 0 "NULL" on ERROR.
 */

t_list	*arg_switch(t_list *a, int argc, char **argv)
{
	if (argc == 2)
	{
		a = s_arg_parse(argv[1]);
		if (!a)
			return (0);
		return (a);
	}
	else if (argc > 2)
	{
		a = m_arg_parse(argv);
		if (!a)
			return (0);
		return (a);
	}
	return (0);
}

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
