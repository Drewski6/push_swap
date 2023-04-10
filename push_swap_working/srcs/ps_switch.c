/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:04:14 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/10 17:04:28 by dpentlan         ###   ########.fr       */
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
